#include <bits/stdc++.h>
using namespace std;

const int N = 100001;
int ans[N];

void merge(pair<int, int> a[], int start,
           int mid, int end)
{
    pair<int, int> f[mid - start + 1],
        s[end - mid];

    int n = mid - start + 1;
    int m = end - mid;

    for (int i = start; i <= mid; i++)
        f[i - start] = a[i];
    for (int i = mid + 1; i <= end; i++)
        s[i - mid - 1] = a[i];

    int i = 0, j = 0, k = start;
    int cnt = 0;

    while (i < n && j < m)
    {
        if (f[i].second <= s[j].second)
        {
            ans[f[i].first] += cnt;
            a[k++] = f[i++];
        }
        else
        {
            cnt++;
            a[k++] = s[j++];
        }
    }

    while (i < n)
    {
        ans[f[i].first] += cnt;
        a[k++] = f[i++];
    }

    while (j < m)
    {
        a[k++] = s[j++];
    }
}


void mergesort(pair<int, int> item[],
               int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    mergesort(item, low, mid);
    mergesort(item, mid + 1, high);
    merge(item, low, mid, high);
}


int main()
{

    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int a; cin>>a;
        arr.push_back(a);
    }

    pair<int, int> a[n];
    memset(ans, 0, sizeof(ans));

    for (int i = 0; i < n; i++)
    {
        a[i].second = arr[i];
        a[i].first = i;
    }

    mergesort(a, 0, n - 1);
    long long soma =0;
    for(int i=0;i<n;i++)
        soma+=ans[i];
    cout<<soma<<endl;

    return 0;
}