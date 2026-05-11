## Lower Bound
    Definition: First position where value >= target
    i.e. the leftmost valid position

## Upper Bound
	Definition: First position where value > target
	i.e. the first strictly greater element

## C++ STL

### lower_bound() 
Returns iterator to first element >= target

    auto it = lower_bound(arr.begin(), arr.end(), target);
    
###  upper_bound()
Returns iterator to first element > target

    auto it = upper_bound(arr.begin(), arr.end(), target);

### Convert iterator to index
    int index = it - arr.begin();

### Count Occurances
    int count = upper_bound(arr.begin(), arr.end(), target) - lower_bound(arr.begin(), arr.end(), target);

### Binary Search (existence check)
    bool exists = binary_search(arr.begin(), arr.end(), target);

### first occ
    int first = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

### last occ
    int last = upper_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;