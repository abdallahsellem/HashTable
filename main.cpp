#include <bits/stdc++.h>

using namespace std;
const int MOD = 9973;
#define iso ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

class LinkedNode {

public:
    LinkedNode(LinkedNode *node, int value, int hash) {
        Next = node;
        val = value;
        hashing = hash;
    }

    LinkedNode *Next;
    int val = 0;
    int hashing = 0;

};

class HashTable {
    LinkedNode *arr[MOD-1];

public:


    void InsertVal(int val, int hashing) {
        int index = hashing % MOD;
        LinkedNode *Curr = arr[index];
        if (Curr == nullptr) {
            LinkedNode *node = new LinkedNode(nullptr, val, hashing);
            arr[index] = node;
        } else {
            while (Curr->Next != nullptr) {
                Curr = Curr->Next;

            }
            LinkedNode *node = new LinkedNode(nullptr, val, hashing);
            Curr->Next = node;
        }
    }

    bool CountVal(int hashing) {
        int index = hashing % MOD;
        LinkedNode *Curr = arr[index];
        while (Curr!= nullptr) {
            if (Curr->hashing == hashing) {
                return true;
            }
            Curr = Curr->Next;

        }
        return false;
    }

    int GetVal(int hashing) {
        int index = hashing % MOD;
        LinkedNode *Curr = arr[index];
        while (Curr != nullptr) {
            if (Curr->hashing == hashing) {
                return Curr->val;
            }
            Curr = Curr->Next;

        }
        return -1;
    }


};

int32_t main() {
    HashTable map = *new HashTable();
    map.InsertVal(2, 7);
    map.InsertVal(12, 17);
    map.InsertVal(5, 2);
    cout << map.GetVal(2)<<endl;
    cout<<map.GetVal(17)<<endl ;

    return 0;
}
