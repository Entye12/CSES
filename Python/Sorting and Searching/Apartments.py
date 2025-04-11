line = input().split(" ")
applicants = input().split(" ")
apartments = input().split(" ")

n,m,k = int(line[0]),int(line[1]),int(line[2])

applicants, apartments = [int(x) for x in applicants],[int(x) for x in apartments]
applicants.sort()
apartments.sort()


ans = 0
cur_applicant, cur_apartment = 0,0

while cur_applicant < n and cur_apartment < m :
    if applicants[cur_applicant]-k <= apartments[cur_apartment] <= applicants[cur_applicant]+k :
        ans += 1
        cur_applicant += 1
        cur_apartment += 1
    
    elif apartments[cur_apartment] > applicants[cur_applicant]+k:
        cur_applicant += 1
    
    else : 
        cur_apartment += 1

print(ans)