import time
import random

def predicat(first, second):
    if first < second:
        return True
    else:
        return False

def heapify(nums, heap_size, root_index, pred):
    largest = root_index
    left_child = (2*root_index) + 1
    right_child = (2*root_index) + 2
    if pred:
        if left_child < heap_size and nums[left_child] > nums[largest]:
            largest = left_child

        if right_child < heap_size and nums[right_child] > nums[largest]:
            largest = right_child

        if largest != root_index:
            nums[root_index], nums[largest] = nums[largest], nums[root_index]
            heapify(nums, heap_size, largest, pred)

    else:
        if left_child < heap_size and nums[left_child] < nums[largest]:
            largest = left_child

        if right_child < heap_size and nums[right_child] < nums[largest]:
            largest = right_child

        if largest != root_index:
            nums[root_index], nums[largest] = nums[largest], nums[root_index]
            heapify(nums, heap_size, largest, pred)


def heap_sort(nums, first, second):
    n = len(nums)

    pred = predicat(first, second)

    for i in range(n, -1, -1):
        heapify(nums, n, i, pred)

    for i in range(n-1, 0, -1):
        nums[i], nums[0] = nums[0], nums[i]
        heapify(nums, i, 0, pred)

if __name__ == '__main__':
    nums = []
    for i in range(100):
        nums.append(random.randint(0, 1000))

    first = input("Enter first: ")
    second = input("Enter second: ")
    startTime = time.time()
    heap_sort(nums, first, second)
    print(nums, '\nTime taken:', "%s seconds" % (time.time() - startTime))
