#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
// 백준  1927
// 알고리즘 분류 '힙'
// https://www.acmicpc.net/problem/1927
// stl와 실제 구현 두가지 버전
int main(void) {
    priority_queue<int, vector<int>, greater<int>>pq;
    int n = 0;
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        int t;
        scanf("%d", &t);
        if (t== 0) {
            if(pq.size() == 0) {
                cout << 0 << "\n";
                continue;
            } else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        } else {
            pq.push(t);
        }
        
    }
}
    //int arr[N] = {0};
    //int main(void) {
    //    int n = 0;
    //    int heap_size = 0;
    //    int idx = 1;
    //    scanf("%d",&n);
    //    for (int i=0;i<n;i++) {
    //        int t;
    //        scanf("%d", &t);
    //
    //        if (t == 0) {
    //            // 제거
    //            if (heap_size == 0) cout << 0 << "\n";
    //            else if (heap_size == 1) {
    //                cout  << arr[1] << "\n";
    //                arr[1] = 0; heap_size = 0;
    //            }
    //            else {
    //                cout  << arr[1] << "\n";
    //                arr[1] = arr[heap_size--];
    //                for (int start = 1; start<heap_size;) {
    //                    if(arr[start] > arr[start*2]) {
    //                        int tmp = arr[start];
    //                        arr[start] = arr[start*2];
    //                        arr[start*2] = tmp;
    //                        start = start * 2;
    //                    } else if (arr[start] > arr[start*2+1]) {
    //                        int tmp = arr[start];
    //                        arr[start] = arr[start*2+1];
    //                        arr[start*2+1] = tmp;
    //                        start = start * 2+1;
    //                    } else {
    //                        break;
    //                    }
    //                }
    //
    //
    //            }
    //            continue;
    //        }
    ////        cout << "heap size : " << heap_size << "\n";
    //        if (heap_size == 0) {
    //            heap_size ++;
    //            arr[1] = t; continue;
    //        }
    //        idx = ++heap_size;
    //        while(idx!= 1 && t < arr[idx/2]) {
    //            arr[idx] = arr[idx/2];
    //            idx/=2;
    //        }
    ////        cout << "insert idx : " << idx << "\n";
    //        arr[idx] = t;
    //    }
    //}
