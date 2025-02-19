// Merge K sorted linked lists


class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
     priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
     
     for(int i = 0; i< arr.size(); i++){
         if(arr[i]){
             pq.push({arr[i]->data, arr[i]});
         }
     }
     
     Node* demo = new Node(-1);
     Node* temp = demo;
     
     while(!pq.empty()){
         auto it = pq.top();
         pq.pop();
         
         temp->next = it.second;
         if(it.second->next) pq.push({it.second->next->data, it.second->next});
         temp = temp->next;
     }
     return demo->next;
    }
};
