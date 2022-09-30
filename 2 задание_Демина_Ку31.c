#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

void create_arr(double* array, int size){
  srand(time(NULL));
  for(int i = 0;i < size;i++){
    array[i] = (double)(rand() % 101 + (-50)) + (double)(rand() % 100)/100; 
  }
}

double average(double* array, int size){
  double sum = 0.0;
  for(int i = 0;i < size;i++){
    sum += array[i];
  }
  return sum/size;
}

void print_arr(double* array, int size){
  for(int i = 0;i < size;i++){
    printf("arr[%d] = %0.2lf \n", i, array[i]);
  }
}

int count_moreSum(double* array, int size){
  double sum_num = average(array, size);
  int count = 0;
  for(int i = 0;i < size; i++){
    if(array[i] > sum_num)
      count++;
  }
  return count;
}

double sum_after_minus(double* array, int size){
  int flag = 0;
  int indx = -1;
  double sum = 0;
  for(int i = 0;i < size; i++){
    if(array[i] < 0){
      flag = 1;
      indx = i+1;
      break;
    }
  }
  if(flag != 0 && indx < size)
    for(indx; indx < size;indx++)
      sum+= fabs(array[indx]);
  return sum;
}


int main(){
int n = 0;
printf("Enter size arr: ");
scanf("%d", &n);
if(n <= 0){
printf("size must be more zero!!!");
  return 0;
}
double* arr = (double*)malloc(sizeof(double) * n);

create_arr(arr, n);
print_arr(arr, n);
printf("average = %0.2lf\n", average(arr, n));
printf("%d numbers more average\n", count_moreSum(arr,n));
printf("sum elements after first nagative = %0.2lf\n", sum_after_minus(arr, n)); 

free(arr);
return 0;
}