#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<double, pair<string, int>>> sweep_line;
int rooms = 0;
set<int> available_rooms;
map<int,int> room_to_index;
int s,e;

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d %d",&s,&e);
        sweep_line.push_back({s-0.5,{"start",i}});
        sweep_line.push_back({e,{"end",i}});
    }
    sort(sweep_line.begin(),sweep_line.end(),[](auto &a,auto &b){
        return a.first < b.first;
    });

    for (auto &event:sweep_line){
        double time = event.first;
        string ch = event.second.first;
        int idx = event.second.second;

        if (ch == "start"){
            if (available_rooms.empty()){
                rooms++;
                room_to_index[idx] = rooms;
            }
            else {
                auto it = available_rooms.begin();
                int room = *it;
                available_rooms.erase(it);
                room_to_index[idx] = room;
            }
        }
        else {
            available_rooms.insert(room_to_index[idx]);
        }
    }
    printf("%d\n",rooms);
    for (int i=1;i<=n;i++){
        printf("%d ",room_to_index[i]);
    }
    printf("\n");
    return 0;
}