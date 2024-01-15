#include <iostream>





//Create an array structure with an int pointer, and size and length of the array as member variables
struct Array {

	int* A;
	int size;
	int length;
};



//Insert Element
//--------------------------------------------------------------------------------------//

//Take the array by ADDRESS since it will modify the array
//This is pointing to the OBJECT arr, not a particular arr, just the WHOLE object
//Meaning we can modify its member variables 
void insertElement(struct Array* arr, int index, int value) {

	//Check to see if the size of the array is big enough for another element
	if (arr->length + 1 > arr->size) {

		std::cout << "Error: Array is not big enough" << '\n';

		return;
	};


	// we have to check if the index is valid, which is 0 to the length of the array
	//if you do index < arr-> then you cannot append because it will not insert at the length of the array
	//but if you do <= then it will insert at the next available slot


	if (index >= 0 && index <= arr->length) {

		//Creates a for loop that iterates from the length of the array
		//down to the value of index(where the user wants the value to go)
		for (int i = arr->length; i > index; i--) {

			//A[i] represents the next available location
			//we want to take the last element inside of the array with i-1, and equal it to A[i]
			//this will shift all of the elements up until we hit  index(location of newly inserted value), 
			arr->A[i] = arr->A[i - 1];
		};
		//then we insert our values since everything has been shifted
		arr->A[index] = value;

		//the length of our index has grown by 1 since we inserted a value, so we have to 
		//increase the legnth
		arr->length++;
	};

};










//Append Element
//--------------------------------------------------------------------------------------//

//Inserts a new element at the end of the array
//we will use a pointer as the parameter since we want to change the value by address
void append(struct Array* arr, int x) {


	// This verifies that there is room inside of the array
	//if length = size then there is no room inside of the array
	//Meaning we cannot perform the append logic
	if (arr->length < arr->size) {
		arr->A[arr->length] = x;
		arr->length++;
	}
	else {
		std::cout << "Error: not enough room inside of the array. Cannot perform operation" << '\n';
	}
};







//Delete Element
//--------------------------------------------------------------------------------------//

//Delete an element within an array
//We use int here in order to return a success or failure
//Success will return the element deleted, failure will return 1
//This function requires a pointer for this ADT Array, and the index to be deleted
int deleteElement(struct Array* arr, int index) {

	//Deletion value, initialized
	int deletedValue = 0;


	//Check to see if the index from the input is valid, if it is between
	//0 and the length - 1, since length vacant
	if (index >= 0 && index <= arr->length - 1) {

		//this represents the actual value that we will delete after the for loop
		//this value will get printed back to the user
		deletedValue = arr->A[index];


		//This for loop starts off at the position of index, which is where the user wants to
		//make a deletion, the reason why its up to length - 1 is because:
		//there is no value at length, the last value inside of our array is length - 1
		//So if we go from userIndex < length, then our logic will copy the content
		// of length  and place it into length -1, which is incorrect, we are only worried about
		// the elements within our array, and length is not apart of our array
		for (int i = index; i < arr->length - 1; i++) {

			//transfers the content of index + 1, into index, which shifts everything to the left
			arr->A[i] = arr->A[i + 1];
		}

		//Decrease the length by 1 since we removed a value
		arr->length--;

		//return the deleted value back to user
		return deletedValue;
	};

	//if the user enters an invalid index, return 1 instead to signify an error
	std::cout << "Invalid Index. Please Try Again." << '\n';

	return 1;
};






//Get Index of Element
//--------------------------------------------------------------------------------------//

//Return the index at which the element is stored at
int getIndex(struct Array arr, int element) {

	//Use a for loop to iterate through the array's length
	for (int i = 0; i < arr.length; i++) {

		//if the element is equal, return the index
		if (element == arr.A[i]) {
			return i;
		}
		
	}
		std::cout << "Element not found within this array. Try again" << '\n';
		return -1;
		
};







//Swap Elements 
//-------------------------------------------------------------------------------------//
//Create a swap function to swap the values of two elements by address
//This swap function is necessary to perform transposition or Move to Head logic on an array
//to swap two elements after a search query in order to speed up performance
void swapElements(int* x, int* y) {

	int temp;
	

	temp = *x;
	
	//very subtle blunder, i originally had *y = *x but it should be *x = *y
	//since we want to store x in temp, and give x the value of y
	*x = *y;

	*y = temp;

};




//Set Elements 
//-------------------------------------------------------------------------------------//
//Set a value within an array
//Since we are changing the values within the array, we have to use a pointer
//We will use the int data type to return 0 for success and 1 for failure
int setElement(struct Array* arr, int index, int set) {

	//Checks if the index the user input is valid and within the bounds of the array
	if (index >= 0 && index < arr->length) {

		//stores the value of the user set at the specified index within the array
		arr->A[index] = set;

		//returns 0 to signify success
		return 0;
	}

	std::cout << "Invalid Index. Try again";
	//returns -1 to signify failure
	return -1;
};







//Min Element
//-------------------------------------------------------------------------------------//

//Close to the same logic as max but instead we have a min variable
//We use int data type since we are returning min
int minElement(struct Array arr) {

	//create a min variable that holds the first element within the array
	int min = arr.A[0];

	//create a for loop to iterate through the array starting at index 1, since 
	//we stored index 0 and will use that value to check the other elements
	for (int i = 1; i < arr.length; i++) {

		//if the element at index i is less than min, then replace min with A[i]
		if (arr.A[i] < min) {

			min = arr.A[i];
		};
	};

	//return min
	return min;

};






//Max Element
//-------------------------------------------------------------------------------------//
//Get the max element within an array
//int data type since we are returning the max value
//only parameter is the array
int maxElement(struct Array arr) {

	//create a max variable that will start at the beginning of the array
	int max = arr.A[0];

	//since our max is already set to the value at the beginning of the array
	//all is left is for us to check that value with every other element in the array
	//which will take O(n), this is the only way with an unsorted array,
	//If the array was sorted then we would take the value of length - 1
	for (int i = 1; i < arr.length; i++) {

		//if we find a value that is greater than max, then we change max to the new value
		//at that specific index
		if (arr.A[i] > max) {

			max = arr.A[i];
		};
	}

	return max;
};





































int main() { 
	
	//Create an Array object
	struct Array array1;




	//Create variables
	int index;
	int element;
	int element2;


	//Ask user to input Array Size
	std::cout << "Enter the size you want your array to be: ";
	std::cin >> array1.size;
	
	//Initialize the value of Array Object's length to 0
	array1.length = 0;

	//Dynamically create an object array based off user input
	array1.A = new int[array1.size];





	//Ask user for index and element to insert into array
	std::cout << "Enter an Index and Element to insert into array: ";
	std::cin >> index;
	std::cin >> element;
	

	//Insert Element
	insertElement(&array1, index, element);







	//Ask user what value they would like to append to the existing array
	std::cout << "Enter a Value that you would like to append to the array: ";
	std::cin >> element;

	//Append Element
	append(&array1, element);





	//Ask user at which index would they like to delete a value?
	std::cout << "Enter the Index at which you would like to delete a value: ";
	std::cin >> index;

	//Delete Element
	deleteElement(&array1, index);




	//Ask user to enter an element to get its index
	std::cout << "Enter a value within the array to obtain its index: ";
	std::cin >> element;

	//show the index
	std::cout << getIndex(array1, element) << '\n' << '\n';





	//Ask user to enter two elements to swap
	//We will use the getIndex function, to find both indexes of the elements
	//In order to pass elements in the swap functions parameters
	//SwapElements function takes in the memory addresses in order to swap
	std::cout << "Enter two elements to swap within the array: ";
	std::cin >> element;
	std::cin >> element2;
	swapElements(&array1.A[getIndex(array1, element)], &array1.A[getIndex(array1, element2)]);

	

	


	//Ask the user to enter an Index and Element to set value
	std::cout << "Set an element by entering the Index and new Element Value: ";
	std::cin >> index;
	std::cin >> element;
	setElement(&array1, index, element);






	//Find the min element
	std::cout << "Min Element is: " << minElement(array1) << '\n' << '\n';



	//Find the max element
	std::cout << "Max Element is: " << maxElement(array1) << '\n' << '\n';




	//Display Element
	for (int i = 0; i < array1.length; i++) {
		std::cout << array1.A[i] << '\n';
	};

	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0; 

};