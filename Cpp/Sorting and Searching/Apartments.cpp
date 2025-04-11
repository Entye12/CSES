#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int ans = 0;
int cur_applicant = 0; int cur_apartment = 0;
int x,y;
vector<int> applicants,apartments;

int main(){
    scanf("%d %d %d",&n,&m,&k);
    for (int i=0; i<n; i++){
        scanf("%d",&x);
        applicants.push_back(x);
    }
    for (int i=0; i<m; i++){
        scanf("%d",&y);
        apartments.push_back(y);
    }
    sort(applicants.begin(), applicants.end()); sort(apartments.begin(), apartments.end());

    while (cur_applicant < n && cur_apartment < m){
        if (applicants[cur_applicant]-k <= apartments[cur_apartment] && apartments[cur_apartment] <= applicants[cur_applicant]+k ){
            ans++; cur_applicant++; cur_apartment++;
        }
        else if (apartments[cur_apartment] < applicants[cur_applicant]-k) cur_apartment++;
        else cur_applicant++;
    }
    printf("%d\n",ans);
    return 0;
}