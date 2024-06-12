typedef int SortElementType;  // Defines the data type

int sortCompare(SortElementType e1, SortElementType e2){
  if(e1 > e2) return 1;
  else if(e1 == e2) return 0;
  else if(e1 < e2) return -1;
}

void swap(SortElementType *a, SortElementType *b){
  SortElementType tmp = *a;
  *a = *b;
  *b = tmp;
}

/***************************  Bubble sort ************************************/
void bubble_sort(SortElementType a[], int n) {
  int i, j;
  for(i=0; i<n; i++)
    for(j = i+1; j < n; j++)
      if(sortCompare(a[i],a[j]) == 1) swap(&a[i], &a[j]);
}

/***************************Selection sort ************************************/
void selection_sort(SortElementType a[], int n){
  int i, j, min;
  for(i = 0; i < n; i++){
    min = i;
    for(j = i+1; j < n; j++)
      if(sortCompare(a[j],a[min]) == -1) min = j;
    swap(&a[min], &a[i]);
  }
}

/***************************Insertion sort ************************************/
void insertion_sort(SortElementType a[], int left, int right) {
  for (int i = left + 1; i <= right - left; i++) {
    SortElementType x = a[i];
    int j = i;
    while (j > left && sortCompare(a[j - 1],x) == 1) {
      a[j] = a[j - 1];
      j--;
    }
    a[j] = x;
  }
}

/***************************Quick sort ************************************/
int partition1(SortElementType arr[], int left, int right) {  // selects the pivot as the median element
  int i = left, j = right;
  SortElementType pivot = arr[(left + right) / 2];

  while (i <= j) {
      while (sortCompare(pivot,arr[i]) == 1)
            i++;
      while (sortCompare(arr[j],pivot) == 1)
            j--;
      if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
      }
  };
  return i;
}

void quick_sort1(SortElementType list[], int left, int right){
  int pivot;
  if(left < right){
    pivot = partition1(list, left, right);
    if(left < pivot)
      quick_sort1(list, left, pivot - 1);

    if(right > pivot)
      quick_sort1(list, pivot, right);
  }
}

int partition2(SortElementType arr[], int left, int right) { // selects the pivot as the left-most element
  int i = left + 1, j = right;
  SortElementType pivot = arr[left];

  while (i <= j) {
      while (sortCompare(pivot,arr[i]) == 1)
            i++;
      while (sortCompare(arr[j],pivot) == 1)
            j--;
      if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
      }
  };
  swap(&arr[j], &arr[left]);
  return j;
}

void quick_sort2(SortElementType list[], int left, int right){
  int pivot;
  if(left < right){
    pivot = partition2(list, left, right);
    if(left < pivot)
      quick_sort2(list, left, pivot - 1);

    if(right > pivot)
      quick_sort2(list, pivot + 1, right);
  }
}

int partition3(SortElementType arr[], int left, int right) { // selects pivot as any element
  int i = left, j = right;
  SortElementType pivot = arr[rand()%(right - left + 1) + left];

  while (i <= j) {
      while (sortCompare(pivot,arr[i]) == 1)
            i++;
      while (sortCompare(arr[j],pivot) == 1)
            j--;
      if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
      }
  };
  return i;
}

void quick_sort3(SortElementType list[], int left, int right){
  int pivot;
  if(left < right){
    pivot = partition3(list, left, right);
    if(left < pivot)
      quick_sort3(list, left, pivot - 1);
    if(right > pivot)
      quick_sort3(list, pivot, right);
  }
}

/***************************Heap sort ************************************/
void adjust(SortElementType *list, int root, int n){
  int child = root*2;
  while(child <= n) {
    if(child < n && sortCompare(list[child+1],list[child]) == 1)  // compares the left and right child nodes
      child++;

    if(sortCompare(list[child],list[child/2]) == 1) {             // compare the parent node and the longer node
      swap(&list[child/2], &list[child]);
      child *= 2 ;
    }
    else break;
  }
}

void heap_sort(SortElementType *list, int n){
  for(int i = (n-1)/2; i >= 0; i--) adjust(list,i,n-1);
  for(int i = n-1; i > 0; i--) {
    swap(&list[0], &list[i]);
    adjust(list,0,i-1);
  }
}

/*************************** Merge sort ************************************/
void merge(SortElementType a[], int left, int mid, int right){
  int i = left, j = mid + 1, k = 0;
  SortElementType *tmp = malloc(sizeof(int)*(right-left+2));
  while(1){
    if(sortCompare(a[j],a[i]) == 1){
      tmp[k++] = a[i++];
    }
    else if(sortCompare(a[i],a[j]) == 1){
      tmp[k++] = a[j++];
    }
    else {
      tmp[k++] = a[i++];
      tmp[k++] = a[j++];
    }

    if(i > mid) {
      for(j;j <= right;j++)
        tmp[k++] = a[j];
      break;
    }
    if(j > right) {
      for(i;i <= mid;i++)
        tmp[k++] = a[i];
      break;
    }
  }
  for(i = 0; i < k; i++)
    a[i+left] = tmp[i];
}

void merge_sort(SortElementType a[], int left, int right){
  int mid;
  if(left < right){
    mid = (left + right)/2;
    merge_sort(a, left, mid);
    merge_sort(a, mid + 1, right);
    merge(a, left, mid, right);
  }
}
