# https://www.hackerrank.com/contests/smart-interviews/challenges/si-cabinets-partitioning/copy-from/1319494535

'''You are given a job which has been divide into N tasks. The task cannot be divided any further. Each of the N tasks takes Si number of seconds to complete. Your job will be completed when all your tasks are completed. You have K workers at your disposal to help you complete the tasks. But as per the nature of the job, a worker can only be allocated continuous tasks. A worker can work only on a single task at any given point of time. However, the workers can work in parallel on different tasks. You have to find the minimum possible time in which you can complete the job.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines. First line of each test case contains N and K - number of tasks and available workers for the current job, separated by space. The next line contains N positive integers - denoting the time taken to complete the ith task.

Constraints

50 points
1 <= N,K <= 20

150 points
1 <= N,K <= 10000

General Constraints
1 <= T <= 50
1 <= Si <= 103

Output Format

For each test case, print the minimum possible time in which you can complete the job, separated by newline.

Sample Input 0

6
10 3
1 10 13 4 5 12 23 12 18 8
8 4
17 27 22 45 26 32 45 16
2 2
74 61
7 3
74 24 61 81 66 76 51
2 1
54 10
4 2
15 30 10 50

Sample Output 0

38
66
74
159
64
55

'''

__author__ = "sheetansh"

# solution 1:
def check(arr, mid, n, k):
    s = 0
    count = 0
    for i in arr:
        if i > mid:
            return False
        s += i
        if s > mid:
            s = i
            count += 1
    count += 1
    if count <= k:
        return True
    return False


def partitionCabinet(arr, n, k):
    total = sum(arr)
    low = 1
    high = total
    ans = 0
    while (low <= high):
        mid = (low + high) // 2
        if (check(arr, mid, n, k)):
            ans = mid
            high = mid - 1
        else:
            low = mid + 1
    return ans


for _ in range(int(input())):
    n, k = list(map(int, input().split()))
    arr = list(map(int, input().split()))
    print(partitionCabinet(arr, n, k))


# solution 2 not working correctly

def cabinetPartition(arr, k, cans, ans, idx):
    if(k == 1):
        cans = max(cans, sum(arr[idx:len(arr)]))
        ans = min(cans, ans)
        return ans
    cursum = 0
    for i in range(idx, len(arr)-k+1):
        cursum += arr[i]
        ans = cabinetPartition(arr, k-1, max(cans, cursum), ans, i+1)
    return ans



if __name__ == '__main__':
    for _ in range(int(input())):
        n,k = map(int, input().split())
        arr = list(map(int, input().split()))
        if k == 1:
            print(sum(arr))
            continue
        print(cabinetPartition(arr, k, 0, (1<<31)-1, 0))