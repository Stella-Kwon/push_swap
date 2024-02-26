
def merge_sort(arr):
   # Base case: If the array has one or zero element, it's already sorted
  if len(arr) <= 1:
      return arr

  # Divide the array into two halves
  mid = len(arr) // 2
  left_half = arr[:mid]
  right_half = arr[mid:]

  # Recursively sort both halves
  left_half = merge_sort(left_half)
  right_half = merge_sort(right_half)

  # Merge the sorted halves
  print ("left_half : ", left_half)
  print ("right_half : ", right_half)
    
  return merge(left_half, right_half)
  
def merge(left, right):
  result = []
  left_index, right_index = 0, 0

  # Traverse both left and right arrays
  while left_index < len(left) and right_index < len(right):
      if left[left_index] < right[right_index]:
          result.append(left[left_index])
          print("left[left_index] : ", left[left_index])
          print("result: ", result)
          input()
          left_index += 1
      else:
          result.append(right[right_index])
          print("right[right_index] : ", right[right_index])
          print("result: ", result)
          input()
          right_index += 1

  # If left array still has elements, add them to result
  while left_index < len(left):
      result.append(left[left_index])
      print("still_left : ", left[left_index])
      print("result: ", result)
      input()
      left_index += 1

  # If right array still has elements, add them to result
  while right_index < len(right):
      result.append(right[right_index])
      print("still_right : ", right[right_index])
      print("result: ", result)
      input();
      right_index += 1

  return result

# Example usage
def main() : 
    arr = [38, 27, 15, 3, 9, 7, 10]
    sorted_arr = merge_sort(arr)
    print(sorted_arr)  # Expected output: [3, 9, 10, 27, 38, 43, 82]

if __name__ == "__main__":
    main()