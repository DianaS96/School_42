# Push_swap :1234:	:thinking:	
In this repo you can find program named **push_swap** that represents sorting algoritm that uses 2 stacks and a set of instructions to manipulate both stacks.

Push_swap program sorts input integers integers in ascending order using <a href="https://en.wikipedia.org/wiki/Radix_sort">**`Radix sort algoritm`**</a>.

You can find list of operations to manipulate stacks below:
<details>
  <summary>Click to expand!</summary>
  
  * sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
  * sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
  * ss : sa and sb at the same time.
  * pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
  * pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
  * ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
  * rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
  * rr : ra and rb at the same time. 
  * rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
</details>

## Usage
To run the program do the following:
* clone this repo;
* create executable file **push_swap** running **make** or **make re** in terminal window;
* execute program with command: **`./push swap {int_1}, ..., {int_n}`**.

In case of wrong input (duplicates/numbers greater than MAX_INT/numbers less than MIN_INT/input contain smth else than digit (letter/symbol/etc)) you will get error message.

