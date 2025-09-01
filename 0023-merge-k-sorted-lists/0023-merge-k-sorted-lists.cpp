/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//  //----------------------MinHeap(PQ)-------------------------
// class Solution {
// public:
//     struct compare{
//         bool operator()(ListNode* a, ListNode* b){
//             return a->val > b->val; //min-heap
//         }
//     };

//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         priority_queue<ListNode*, vector<ListNode*>, compare> pq;

//         //push all list heads into heap
//         for(auto node:lists){
//             if(node)pq.push(node);
//         }

//         ListNode dummy(0);
//         ListNode* tail = &dummy;

//         while(!pq.empty()){
//             ListNode* node = pq.top();
//             pq.pop();
//             tail->next = node;
//             tail = tail->next;
//             if(node->next)pq.push(node->next);
//         }

//         return dummy.next;
//     }

// };


// -----------------------Divide&Conquer-------------------------


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        while(lists.size() > 1){
            vector<ListNode*> mergedLists;

            for(int i = 0; i < lists.size(); i += 2){
//We are merging two lists at a time (lists[i] and lists[i+1]).
// After merging those two, we move on to the next pair.
// That’s why we jump by 2 instead of 1.
            ListNode* l1 = lists[i];
            ListNode* l2 = (i + 1 < lists.size()) ? lists[i + 1]: nullptr;
            mergedLists.push_back(mergeList(l1,l2));
            }
            lists = mergedLists; // replace old lists with merged ones
        }
        return lists[0];
    }

    ListNode* mergeList(ListNode* l1, ListNode* l2){
        ListNode dummy;
        ListNode* tail = &dummy;

        while(l1 && l2){
            if(l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
            }else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        if(l1){
            tail->next = l1;
        }else if(l2){
            tail->next = l2;
        }

        return dummy.next;
    }
};