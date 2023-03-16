
#define FALSE   0   //!< 逻辑非
#define TRUE    1   //!< 逻辑是

#define NUM_0_ASCII_CODE 48 //!< 字符'0'的ASC码
#define NUM_1_ASCII_CODE 49 //!< 字符'1'的ASC码

#define MAX_DIGIT_NUMBER 8                  //!< 关键字项数的最大值

int BUCKETS[10];

template <typename info_t, typename DIGIT_TYPE>
struct static_linked_list_node_t {
    DIGIT_TYPE key[MAX_DIGIT_NUMBER];   //!< 关键字
    info_t info;                        //!< 其他数据项
    int next;                           //!< 下一结点的索引
}; 


template <typename info_t, typename DIGIT_TYPE>
struct radix_static_linked_list_t {
    static_linked_list_node_t elements[100];    //!< 元素的静态链表, elements[0]为头结点(不保存元素)
    int number_of_digit;    //!< 基数关键字个数
    int length;             //!< 静态链表长度
};


template <typename info_t, typename DIGIT_TYPE>
void DistributeIntoBuckets(radix_static_linked_list_t<info_t, DIGIT_TYPE>* static_linked_list,
                           int place_of_digit,
                           int* digit_bucket_heads,
                           int* digit_bucket_tails)
{
    /// ### 1 各基数桶(队列)初始化为空 ###
    /// &emsp; **for loop** 遍历基数数位 :\n
    /// &emsp;&emsp; 基数桶的首元素数组(队头数组)各项设置为0\n
    /// &emsp;&emsp; 基数桶的尾元素数组(队尾数组)各项设置为0\n
    for (int j = 0; j < RADIX_10; j++) {
        digit_bucket_heads[j] = 0;
        digit_bucket_tails[j] = 0;
	}

    /// ### 2 求数位在元素数组中的索引###
    int place_index = static_linked_list->number_of_digit - place_of_digit;

    /// ### 3 遍历静态链表, 执行分配 ###
    static_linked_list_node_t* elements = static_linked_list->elements;
    /// &emsp; **for loop** 遍历静态链表各元素 :\n
	for (int i = elements[0].next; i != 0; i = elements[i].next) {

        /// &emsp;&emsp; 取第i个元素, 数位place_of_digit的数位值\n
        int place_value = ord(static_linked_list->elements[i].key, place_index);

        /// &emsp;&emsp; **if** 该数位对应的桶(队列)为空 :\n
        if (!digit_bucket_heads[place_value]) {
            /// &emsp;&emsp;&emsp; 该数位的数组索引place_index入队(进桶)\n
            digit_bucket_heads[place_value] = i;
        } else {    /// &emsp;&emsp; **else** (如果该数位对应的桶(队列)不为空\n
            /// &emsp;&emsp;&emsp; 队尾元素的next, 指向place_index(即加入队尾)\n
            elements[digit_bucket_tails[place_value]].next = i;
        }

        /// &emsp;&emsp; 更新该数位队尾数组元素值\n
        digit_bucket_tails[place_value] = i;
	}
}


/*!
 * 基数排序收集桶
 * @param elements **静态链表元素数组**
 * @param digit_bucket_heads **基数桶的首元素数组**(队头数组)
 * @param digit_bucket_tails **基数桶的尾元素数组**(队尾数组)
 * @note
 * 基数排序收集桶
 * ------------
 * ------------
 * digit自小至大, 将digit_queue_heads[0 ... 9]所指各桶, 依次连接成一个链表
 */
template <typename info_t, typename DIGIT_TYPE>
void CollectBuckets(static_linked_list_node_t<info_t, DIGIT_TYPE>* elements,
                    int* digit_bucket_heads,
                    int* digit_bucket_tails)
{

    /// ### 1 找到第一个非空桶(队列) ###
    /// &emsp; 遍历digit_bucket_heads, 找到第一个非空桶\n
    int place_value = 0;
    while (digit_bucket_heads[place_value] == 0) {
        place_value++;
    }

    /// &emsp; elements[0].next指向第一个非空桶的首结点(第一个非空队列的队头)\n
    elements[0].next = digit_bucket_heads[place_value];
    /// &emsp; 变量digit_bucket_tail保存当前非空桶的最后1个元素
    int digit_bucket_tail = digit_bucket_tails[place_value];

    /// ### 2 执行桶收集 ###
    /// &emsp; **for loop** 数位从0到9 :\n
    while (place_value < 10) {

        /// &emsp;&emsp; 寻找下一个非空桶\n
        place_value++;
        while (place_value < RADIX_10 && digit_bucket_heads[place_value] == 0) {
            place_value++;
        }

        /// &emsp;&emsp; **if** 找不到非空桶 : \n
        /// &emsp;&emsp;&emsp; 退出
        if (place_value == RADIX_10) {
            break;
        }

        /// &emsp;&emsp; 前一非空桶的最后一个元素(队尾元素)elements[digit_bucket_tail]的next, 指向当前数位对应的非空桶的首个元素的索引(队头)
        elements[digit_bucket_tail].next = digit_bucket_heads[place_value];
        /// &emsp;&emsp; 更新digit_bucket_tail值为当前非空桶的最后一个元素的索引(队尾);
        digit_bucket_tail = digit_bucket_tails[place_value];
    }

    /// &emsp; 最后一个非空桶的最后一个元素(队尾元素)的next指向0
    elements[digit_bucket_tail].next = 0;
}


/*!
 * <h1>基数排序</h1>
 * @param static_linked_list **待排序静态链表**
 * @note
 */
template <typename info_t, typename DIGIT_TYPE>
void RadixSort(radix_static_linked_list_t<info_t, DIGIT_TYPE>* static_linked_list) {
    int digit_queue_heads[10];  // 基数队列队头数组
    int digit_queue_tails[10];  // 基数队列队尾数组

    /// ### 1 初始化static_linked_list各元素的next ###
    /// &emsp; **for loop** 遍历静态链表, 索引范围[ 1 ... (length - 1) ] : \n
    for (int i = 0; i < static_linked_list->length; ++i) {
        /// &emsp;&emsp; 索引i元素的next, 设置为i + 1 \n
        static_linked_list->elements[i].next = i + 1;
    }

    /// &emsp; 索引length元素的next, 设置为0(构成循环静态链表)
    static_linked_list->elements[static_linked_list->length].next = 0; // 最后一个元素的next指向0

    /// ### 2 按最低位优先(右侧个位开始), 依次对各个位进行分桶和收集 ###
    /// &emsp; **for loop** 从右侧开始, 遍历各个位 :\n
    for (int i = 1; i <= static_linked_list->number_of_digit; i++) {

        /// &emsp;&emsp; 右侧第i位作为基数, 进行分桶 \n
        DistributeIntoBuckets(static_linked_list, i, digit_queue_heads, digit_queue_tails);

        /// &emsp;&emsp; 对分完的桶, 进行收集
        CollectBuckets(static_linked_list->elements, digit_queue_heads, digit_queue_tails);
    }
}
