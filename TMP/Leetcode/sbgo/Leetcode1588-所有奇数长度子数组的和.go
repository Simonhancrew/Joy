package sbgo

func sumOddLengthSubarrays(arr []int) (res int) {
	arr = append([]int{0}, arr...)
	for i := 1; i < len(arr); i++ {
		arr[i] += arr[i-1]
	}
	for i := 1; i < len(arr); i++ {
		for j := i; j < len(arr); j++ {
			if (j-i+1)&1 == 1 {
				res += arr[j] - arr[i-1]
			}
		}
	}
	return
}
