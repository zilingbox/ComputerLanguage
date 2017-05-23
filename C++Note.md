#Hello World#
-------------------
##Preface
*This time is 3/13/2016*

Hello world~My name is ziling,I really want to make my computer skills better,so I choose to learn things.This file you can see just some notes for beginner,if you think this things will help you that  would make me feel good.
Although I will tell you that My English is so poor, so you can see many errors in this poor notes,haaaa~ : ) 
Maybe this file has no one to read,but I will try my best to do!
Wish you have fun~
##The Start 	**C++**

**First I will told some information about the language.**
- The C++ primier 5 edition 
- Hasome vedioes from youtube [The Link](https://www.youtube.com/watch?v=1MKhigIml3E&list=PLmpc3xvYSk4wDCP5zjt2QQXe8-JGHa4Kt)

**Now the wonderful world is coming!**

 **Function**
 A function definition has four elements: a function name,a(posibly empty)parameter list, a return type,and a function body.
 Here is the example:
 

    #include <iostream>
    int main()
    {
        std::cout << "Enter two  numbers:" << std::endl;
        int v1 = 0, v2 = 0;
        std::cin >> v1 >> v2;
        std::cout << "The sum of" << v1 << "and" << v2
                  << "is" << v1+v2 << std::endl;
        return 0;
    }

>**Tips: **the output operator "<<",the left-hand operand must be an ostream;the right-hand operand is a value on the given ostream.

Here is the tips' example:

     std::cout << "Enter two  numbers:" << std::endl;
     //follow sentence is the same
      std::cout << "Enter two  numbers:" 
      std::cout << std::endl;
Writing **endl** has the effect of ending the current line and flushing the **buffer** associated with  that device.Flushing the buffer ensures that all the output is written to the output stream,rather than sitting in memory waiting to be written.

###Home work (1.3-1.6)
Exercise1.3

    #include <iostream>
    int main()
    {
         //This is not the First time to write down this but I feel it very happy~Hope you have the same felling :）
        std::cout << "Hello World~" << std::endl;
        return 0;
    }
Exercise1.4

    #include<iostreame>
    int main()
    {
        std::cout << "Enter two numbers to multiplication:" << std::endl;
        int v1 = 0,v2 = 0;
        std::cin >> v1 >> V2;
        std::cout << "The" << v1 << "multiplication" << v2 << "is"
        << V1*V2 << std::endl;
        return 0;
    }
Exercise1.5

    #include<iostreame>
    int main()
    { 
        std::cout << "This may be fine";
        std::cout << std::endl;
        return 0;
    }
Exercise1.6
~~I guss it is legal.
The CMD will show: 
*The sum of V1 and V2 is V1+V2*~~
Yesterday I put a wrong answer,the right answer is:
It is not legal.Because the 2,3 has the operator ";" that means the sentence is end up.We need to add "std::cout" before the operator "<<" .


**The While Statement**
Here is the example:

    #include<iostream>
    int main()
    {
        int sum = 0, val = 1;
        //keep executing the while as long as val is less than or equal to 10
        while(val <= 10){
        sum += val;
        ++val;
        }
        std::cout << "Sum of 1 to 10 inclusive is"
                  << sum << std::endl;
        return 0;
    }

> **While has the form:**
> While(condition){
> statement
> }

###Home work (1.9-1.11)
Exercise1.9

    #include <iostreame>
    int main()
    {
        int sum = 50, val = 51;
        while(val <= 100){
        sum += val;
        ++val;
        }
        std::cout << "The sum of 50 to 100 is"
                  << sum << std::endl;
        return 0;
    }
   
Here is the another example

        #include <iostreame>
    int main()
    {
        int sum = 0, val = 50;
        while(val <= 100){
        sum += val;
        ++val;
        }
        std::cout << "The sum of 50 to 100 is"
                  << sum << std::endl;
        return 0;
    }

Exercise1.10

    #include <iostream>
    int main()
    {
       int val = 10;
       while (val >= 0){
       std::cout << val << std::endl;
       --val;
       }
       return 0;
    }
Exercise1.11
I think this example is very good~

    #include <iostream>
    int main()
    {
     	int v1 = 0, v2 = 0;
	    std::cout << "Please Enter two numbers:" << std::endl;
	    std::cin >> v1 >> v2;
	    if (v1 > v2) 
		while (v1 >= v2)
		{
			std::cout << v1 << std::endl;//from big to small
			v1--;
		}
	
	    else                            
        while (v1 <= v2)           //from small to big
		{
			std::cout << v1 << std::endl;
			v1++;
		}
	
	   system("pause");
       return 0;
    }
**The For Statement**
Here is the example:

    #include <iostream>
    int main()
    {
       int sum = 0;
       //sum values from 1 through 10 inclusive
       for( int val = 1, val <= 10, ++val){
       sum += val;
       }
       std::cout << "Sum of 1 to 10 inclusive is"
                 << sum << std::endl;
       return 0;
    }
    
###Home work (1.13-1.14)
Exercise1.13

    1.9
    #include <iostream>
    int main()
    {
	    int sum = 0;
	    for (int val = 50; val <= 100; ++val)
	    sum += val;
		std::cout << sum << std::endl;
        return 0;
    }
    -----------------------------------
    1.10
    #include <iostream>
    int main()
    {
        for(int val = 10; val >= 0; --val)
        std::cout << val << std::endl;
        return 0;
    }
    -----------------------------------
     1.11
    #include <iostream>
    int main()
    {
       std::cout << "Please enter two numbers:" << std::endl;
       std::cin >> v1 >> v2;
       if(v1 > v2)      //from big to small
          for(v1 >= v2; --v1)
          std::cout << V1 << std::endl;
       esle
          for(v1 < v2; ++v1) //from small to big
          std::cout << v1 <<std::endl;
       return 0;
    }

Exercise1.14
You will find if the loop is limited , the FOR statement is more simple,else the WHILE statement is more good.

**Reading an Unknown Number of Inputs**

    #include <iostream>
    int main()
    {
        int sum = 0,value = 0;
        while( std::cin >> value)
        sum += value;
        std::cout << "Sum is " << std::endl;
        return 0;
    }
**IF Statement**

    #include <iostream>
    int main()
    {
        int currVal = 0, val = 0;
        if(std::cin >> currVal){ //read a value into currVal
           int cnt = 1;
           while (std::cin >> val){
                if(val == currVall)
                   ++cnt;
                else{
                std::cout << currVal << " occurs "
                          << cnt << "times" << std::endl;
                  currlVal = val; //remember the new value
                  cnt = 1; //reset the counter
                }
           }
           std::cout << currVal << " occurs "
                     << cnt << std::end;
        }
        return 0;
    }
