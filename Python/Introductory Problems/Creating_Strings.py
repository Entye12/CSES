from collections import Counter

string = list(input())
string.sort()
n = len(string)

facto = {0:1, 1:1, 2:2, 3:6, 4:24, 5:120, 6:720, 7:5040, 8:40320}


# Count number of permutations
count = Counter(string)
ans = facto[n]
for key in count:
    ans = ans//facto[count[key]]

############ next permutation !

def next_permutation(nums):
    l,index = len(nums),len(nums)-1
    while index > 0 and nums[index] <= nums[index-1]:
        index -= 1
    
    if index > 0 :
        # look for smallest number in range index,l st the nb is > cur index
        k = l-1 
        while nums[k] <= nums[index-1]:
            k -= 1
        # swap
        nums[k], nums[index-1] = nums[index-1], nums[k]

        # sort the right part [index,n-1]
        left,right = index,l-1
        while left <= right :
            nums[left],nums[right] = nums[right],nums[left]
            left += 1
            right -= 1
    
    else : # the array is decreasing here
        for i in range(l//2):
            nums[i],nums[l-i-1] = nums[l-1-i],nums[i]
    
    return nums


print(ans)

for i in range(ans):
    print("".join(string))
    string = next_permutation(string)