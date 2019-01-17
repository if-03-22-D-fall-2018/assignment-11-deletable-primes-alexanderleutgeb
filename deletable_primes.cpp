/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHDV
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			deletable_primes.h
 * Author:			P. Bauer
 * Due Date:		December 1, 2010
 * ----------------------------------------------------------
 * Description:
 * CatCoder Deletable Primes.
 * ----------------------------------------------------------
 */
#include "deletable_primes.h"
#include <math.h>
unsigned long remove_digit(int index, unsigned long n)
{
 unsigned long digits_before=n/pow(10,index+1);
unsigned long digits_after=n%(unsigned long)pow(10,index);
unsigned long new_number=digits_before*pow(10,index)+digits_after;
return new_number;

}

int get_ways(unsigned long n)
{
  int length = 0;
   for (int i = 0; i < get_length(n); i++)
   {
     if (get_length(n)==1)
     {
       if (is_prime(n)==true)
       {
         return 1;
       }
       return 0;
     }
     else if (is_prime(remove_digit(i,n)))
     {
       length+=get_ways(remove_digit(i,n));
     }
    }
    return length;

}
bool is_prime(unsigned long n)
{
 if (n == 1)
 {
   return false;
 }
 unsigned long newlong = n;
 for (unsigned long i = 2; i <= sqrt(n); i++)
 {
   if (newlong % i == 0)
   {
     return false;
   }
 }
 return true;
}
int get_length(unsigned long n)
{
 unsigned long clone=n;
 unsigned long length=0;
 if (n<10)
 {
   return 1;
 }

 while (clone!=0){
   clone = clone/10;
   length++;
 }
 return length;
}
