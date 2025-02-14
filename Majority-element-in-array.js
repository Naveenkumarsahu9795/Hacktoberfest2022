// JS program to find Majority element in an array
<script>
// findMajority is the function to find Majority element in an array
function findMajority(arr, n)
{
	let maxCount = 0;
	let index = -1;
	
	for(let i = 0; i < n; i++)
	{
		let count = 0;
		for(let j = 0; j < n; j++)
		{
			if (arr[i] == arr[j])
				count++;
		}

		// update the maxCount if count of current element is greater
		if (count > maxCount)
		{
			maxCount = count;
			index = i;
		}
	}

	// If maxCount is greater than n/2 then return the corresponding element
	if (maxCount > n / 2)
		document.write(arr[index]);
	else
		document.write("No Majority Element");
}

// Driver program
let arr = [ 1, 1, 2, 1, 3, 5, 1 ];
let n = arr.length;

// calling of function 
findMajority(arr, n);

</script>
