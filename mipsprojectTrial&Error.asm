#Arianna Cooper's Bubble Sort Code

# when i first attempted this program, I tried to rely heavily on the book for the sort and follow their steps as reference
# however when i tried that approach I got nothing but errors and confusion from loading things on the stack pointer to getting my print function 
# to work correctly.So then I just scrapped the idea after attending tutoring sessions, and recieving help from the si, I decided to create a new one based off of 
# pure c++ code, so i initalized values for my array in i and j, then made sure my outside for loop had the right register values, along with the same for my inner loop
# the constant problem I kept having was that I first kept calling the inner loop before initalizing j then I also didn't realize
# that you could simply just swap the temporary registers for $t4 and $t5 within the function, until right before i fixed my code
# another thing I did trial and error on was with both the swap and the print function, as my print function kept ignoring my sort code since i initally used the wrong registers
#when it came to my swap, I first attemped the regular swap and kept having issues, then i scrapped that and tried to go the opposite way with a dont swap function for my conditional instead
# lastly i just decided to do both as to not get confused so i have a swap function with my now swapped $t registers 
#overall it was a very frustrating process but worth it now that it's done. 

 .data
 unsortedArr: .word 12,23,34,45,56,67,78,89,90,9,8,7,6,5,4,2,1,3,87,21 # here are all of my unsorted values for my array
 size: .word 20 #declares the array size to be 20 
 .text
 
 # Registers and what they stand for
 # $s0 or i represents the outer sorts i value
 #$s1 is j and represents the inner sorts j value
 # $s2 is where  the array is
 # $s3 is the array size
 #t4 will hold the unsortedarr[j]
 #$t5 will hold the unsorted arr[j+1]
 #$t3 is the size-i-1
 #$s4 = size-1
 
 
 main:
 	la $s2, unsortedArr # loads addray address within $t1
 	lw $s3,size #loads the array size into $s3
 	subi $s4,$s3, 1 # assigns $s4 to size - 1
 	jal Sort #calls sort function
 	
 	 # After sorting, print the sorted array
 	 la $s2, unsortedArr   # Load array address again for printing
 	 move $s0, $zero       # Reset iterator for printing
 	 jal printSort         # Call print function
 	 
 	
 	
 Sort:
        move $s0, $zero # i = 0
        
 	outer_for:
 	   bge $s0, $s4, exit_out # if i > (size-1) then exit
	    move $s1,$zero #sets j value to 0 
	    
 	   inner_for: 
 	   	sub $t3, $s3, $s0  #same as #t3 = size-i
 	   	subi $t3, $t3, 1 # now $t3 = size-i-1
 	   	bge $s1, $t3, exit_inner # if j == (size-i-1) then exit inner loop
 	   	
 	   	sll $t1, $s1, 2 # t1= will have value of j *4  inner index
 	   	add $t2, $s2, $t1 # t2= will have the value fo the unsortedArr + the byte address
 	   	lw  $t4,0($t2) # $t4 is now unsortedArr[j]
 	   	lw  $t5,4($t2) # $t5 is now unsortedArr[j+1] because of 4 bit offset
 	   	
 	   	
 	   	bgt $t4, $t5, swap #if unsortedArr[j] > unsortedArr[j+1] then swap them with function
 	   	j Noswap # calls noSwap function
 	   	
 	
 	   	swap: 
 	   	 sw $t5, 0($t2) # places second value in unsortedArr[j]
 	   	 sw $t4, 4($t2) # places first value in unsortedArr[j+1]
 	   	 
 	   	 
 	   	Noswap: # ensures that regardless of swap, j is incremented and repeats the inner_for loop
 	   	addi $s1, $s1,1 #increment j++ for inner loop
 	   	j inner_for	#go back to the inner_for loop that called Noswap
 	  	 
 	   exit_inner: 
 	   addi $s0, $s0,1 #increment i++ for outer loop
 	   j outer_for	#jump back into the outer for loop
 	   	
 	   exit_out:
 	   jr $ra #return after Sort
 	   
 	   
 printSort:
 	bge $s0, $s3,end_program #if the iterator become greater than the size exit the loop
       
       #load word from address and go to next one
       lw $t1, 0($s2) #places sorted array into register $t0
       addi $s2,$s2,4 #points to next element in the now sorted array
       
       # syscall to print
       li $v0,1 # used a 1 since we need to print integers
 	move $a0, $t1 #takes array that was loaded in and places it in $a0
 	syscall
 	
 	#giving space between integers
 	li $v0,11 # prints character for space needed
 	li $a0,32 #needs ascii value for whitespace
 	syscall
       
 	#add counter
 	addi $s0,$s0,1 # works as the iterator
 	j printSort # calls print to keep going
 	
end_program:  # uses 10 for entire program end
 li $v0, 10
 syscall  
 
 	   
 	   
 	   

 	   
 	   