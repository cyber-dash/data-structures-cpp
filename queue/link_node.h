//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/7/14.
//

#ifndef CYBER_DASH_LINK_NODE_H
#define CYBER_DASH_LINK_NODE_H


template <class T>
class LinkNode {

public:
  explicit LinkNode(LinkNode<T>* ptr = NULL): link_(ptr) {}
  explicit LinkNode(const T& data, LinkNode<T> *ptr = NULL): data_(data), link_(ptr) {}

  T GetData() { return data_; }
  bool SetData(const T& data) { data_ = data; return true; }

  LinkNode<T>* GetLink() { return link_; }
  bool SetLink(LinkNode<T>* ptr) { link_ = ptr; return true; }

private:
  T data_;
  LinkNode<T> *link_;
};


#endif //CYBER_DASH_LINK_NODE_H
