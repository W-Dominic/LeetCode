def merge(arr, l, m, r):
    n1 = m - l + 1
    n2 = r - m
    '''
    L = [0] * (n1) # temp array left
    R = [0] * (n2) # temp array right

    # copy data into temp arrays
    for i in range(n1):
        L[i] = arr[l + i]
    for j in range(n2):    
        R[j] = arr[m + 1 + j]
    '''
    L = arr[l:n1+l]
    R = arr[m+1:n2+m+1]

    # merge temp arrays back into arr[l..r]
    i = 0
    j = 0
    k = l
    while(i < n1 and j < n2):
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else :
            arr[k] = R[j]
            j += 1
        k += 1

    # if any data remaining in L or R, copy it to arr
    while(i < n1):
        arr[k] = L[i]
        i += 1
        k += 1
    while(j < n2):
        arr[k] = R[j]
        j += 1
        k += 1
        
def msort(array, left:int, right:int):
    if left < right:
        middle = left+(right - left)//2
        msort(array, left, middle)
        msort(array, middle + 1, right)
        merge(array, left, middle, right)

if __name__ == "__main__":
    arr = [5,3,2,10,1,4,100,50,20,10]
    n = len(arr)
    print(f"Given array: {arr}")
    msort(arr, 0, n-1)
    print(f"Sorted array {arr}")
