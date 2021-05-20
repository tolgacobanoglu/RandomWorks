a = 1234
b = 1234
c = 1234


result_a = (a+1) / 2
result_b = (b+1) / 2
result_c = (c+1) / 2


#i prefer 100 because we don't know what is the result of the square root of 1234. Just we assume that around between 1 - 100
for(i in 1:100)
{
  result_a=1/2*(result_a+(a/result_a))
  if(sqrt(a) == result_a) 
  {
    break;
  }
} 

print(result_a)

while(sqrt(b)<=result_b) 
{
  result_b = (result_b+(b/result_b)) / 2
}

print(result_b)


repeat
{
  result_c = (result_c+(c/result_c)) / 2
  if(sqrt(c)==result_c)
    break;
}

print(result_c)

