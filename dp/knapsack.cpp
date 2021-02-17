#include <iostream>


using namespace std;


int w[6] = { 1, 2, 3, 4, 5, 6};
int v[6] = { 2, 3, 5, 5, 13, 9};
// int v[6] = { 20, 3, 5, 5, 13, 9};

int total_weight = 11;


int main(int argc, char** argv) {

  int K[6][total_weight + 1];
  int prev_idx[6][total_weight + 1];
  int prev_weigth[6][total_weight + 1];

  // init
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j <= total_weight; j++) {
      K[i][j] = 0;
      prev_idx[i][j] = -1;
      prev_weigth[i][j] = -1;
    }
  }

  for (int i = 0; i < 6; i++) {
    K[i][w[i]] = v[i];
  }

  int cur_sum = 0;
  for (int i = 0; i < 6; i++) {

    cur_sum += w[i];

    for (int j = 1; j <= total_weight; j++) {
      if (j < w[i]) {
        if (i - 1 < 0) {
          continue;
        } else {
          K[i][j] = K[i - 1][j];
        }
      } else {
        if (i - 1 < 0) {
          continue;
        } else {
          if (j - cur_sum > 0) {
            continue;
          } else {
            if (K[i - 1][j] >= K[i - 1][j - w[i]] + v[i]) {
              K[i][j] = K[i - 1][j];
            } else {
              K[i][j] = K[i - 1][j - w[i]] + v[i];
              prev_idx[i][j] = i - 1;
              prev_weigth[i][j] = j - w[i];
            }
          }
        }
      }
    }
  }

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j <= total_weight; j++) {
      cout<<K[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;


  for (int i = 0; i < 6; i++) {
    for (int j = 0; j <= total_weight; j++) {
      cout<<prev_idx[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j <= total_weight; j++) {
      cout<<prev_weigth[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;


  return 0;
}
