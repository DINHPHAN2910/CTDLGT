#include<stdio.h>

void nhap_mang(int a[50], int n)
{
	printf("Nhap cac phan tu cua mang: \n");
	for (int i=0; i<n; i++)
	{
		printf("Phan tu thu %d: ",i);
		scanf("%d",&a[i]);
	}
}

void xuat_mang(int a[50], int n)
{
	printf("Cac phan tu cua mang: \n");
	for (int i=0; i<n; i++)
	{
		printf("%d	",a[i]);
	}
	printf("\n");
}

void tim_x(int a[50], int n)
{
    int x, dem = 0;
    printf("Nhap phan tu X can tim kiem trong mang: ");
    scanf("%d", &x);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            dem++;
            printf("Phan tu X duoc tim thay o vi tri a[%d].\n", i);
        }
    }
    if (dem > 0)
    {
        printf("Gia tri X xuat hien %d lan trong mang.\n", dem);
    }
    else
        printf("Khong tim thay phan tu X trong mang.\n");
}

int ktr_so_nguyen_to(int n) 
{
    if (n < 2) 
        return 0;
        
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}


int Dem_SNT(int a[], int n, int vitri[]) 
{
    int dem = 0;
    
    for (int i = 0; i < n; i++) 
	{
        if (ktr_so_nguyen_to(a[i])) 
		{
            vitri[dem] = i; 
            dem++;
        }
    }
    return dem;
}

int main () 
{
	int a[50];
	int x,n;
	
	printf("Nhap so luong phan tu co trong mang: ");
	scanf("%d",&n);
	
	nhap_mang(a,n);
	xuat_mang(a,n);
	tim_x(a,n);
	
	int vitri[n]; 
	
    int soluong = Dem_SNT(a, n, vitri);

    printf("So luong so nguyen to trong mang: %d\n", soluong);
    
    printf("Vi tri cua cac so nguyen to trong mang:\n");
    
    for (int i = 0; i < soluong; i++)
	{
        printf("%d ", vitri[i]);
    }
    printf("\n");
    
}

