void hanoi_towers(int cnt_disk, int i, int k){
    if (cnt_disk ==  1)
        printf("Move disk 1 from pin %d to %d \n" , i , k);
    else {
        int tmp = 6 - i - k;
        hanoi_towers(cnt_disk-1, i, tmp);
        printf("Move disk %d from pin %d to %d \n" , cnt_disk, i , k);
        hanoi_towers(cnt_disk-1, tmp, k);
    }
}

int main()
{
    int cnt_disk, i, k;
    cin >> cnt_disk >> i >> k;
    hanoi_towers(cnt_disk, i, k);
    
}
