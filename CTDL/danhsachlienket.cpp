#include <iostream>
#include <cstring>

using namespace std;

typedef struct SinhVien
{
    long long MSSV;
    char HoTen[30];
    float DTB;
} SV;

struct node
{
    SV info;
    node *next;
};

typedef struct node NODE;

struct list
{
    node *pHead;
    node *pTail;
};

typedef struct list LIST;

void init(LIST &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

node *makenode(SV s)
{
    node *p = new node;
    if (p == NULL)
    {
        cout << "\nKhong du bo nho.";
        return NULL;
    }
    p->info.MSSV = s.MSSV;
    strcpy(p->info.HoTen, s.HoTen);
    p->info.DTB = s.DTB;
    p->next = NULL;
    return p;
}

void AddFirst(LIST &l, node *p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else
    {
        p->next = l.pHead;
        l.pHead = p;
    }
}

void AddLast(LIST &l, node *p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else
    {
        l.pTail->next = p;
        l.pTail = p;
    }
}

void RemoveFirst(LIST &l)
{
    node *p = l.pHead;
    if (l.pHead == NULL)
        cout << "\nDanh sach rong.";
    else
    {
        l.pHead = p->next;
        delete p;
    }
}

void RemoveLast(LIST &l)
{
    node *p = l.pHead;
    node *r = NULL;
    if (l.pHead == NULL)
        cout << "\nDanh sach rong";
    else
    {
        while (p != l.pTail)
        {
            r = p;
            p = p->next;
        }
        l.pTail = r;
        if (r != NULL)
            r->next = NULL;
        delete p;
    }
}

void Nhap(SV &s)
{
    cout << "Ma so sinh vien: ";
    cin >> s.MSSV;
    cin.ignore(); // Loại bỏ ký tự new line còn lại trong buffer.
    cout << "Ho va ten: ";
    cin.getline(s.HoTen, sizeof(s.HoTen));
    cout << "Diem trung binh: ";
    cin >> s.DTB;
}

void InputList(LIST &l)
{
    int n;
    SV s;
    do
    {
        cout << "\nNhap so luong sinh vien: ";
        cin >> n;
        if (n <= 0)
            cout << "So luong sinh vien phai lon hon 0. Vui long nhap lai.";
    } while (n <= 0);

    for (int i = 1; i <= n; i++)
    {
        node *p;
        cout << "\nNhap thong tin sinh vien thu " << i << endl;
        Nhap(s);
        p = makenode(s);
        AddLast(l, p);
    }
}

void Xuat(SV s)
{
    cout << s.MSSV << "\t" << s.HoTen << "\t" << s.DTB << endl;
}

void OutputList(LIST l)
{
    cout << endl
         << "MSSV\tHo va ten\tDiem trung binh" << endl;
    for (node *i = l.pHead; i != NULL; i = i->next)
        Xuat(i->info);
}

void TimKiem(LIST l)
{
    int choice;
    cout << "\nChon cach tim kiem:\n";
    cout << "1. Tim kiem theo MSSV\n";
    cout << "2. Tim kiem theo Ho ten\n";
    cout << "3. Tim kiem theo Diem trung binh\n";
    cout << "Nhap lua chon cua ban: ";
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case 1:
        int x;
        cout << "\nNhap MSSV can tim: ";
        cin >> x;
        for (node *i = l.pHead; i != NULL; i = i->next)
        {
            if (i->info.MSSV == x)
            {
                cout << endl
                     << "MSSV\tHo va ten\t\tDiem trung binh" << endl;
                Xuat(i->info);
                return;
            }
        }
        cout << "Khong ton tai sinh vien co MSSV " << x << endl;
        break;
    case 2:
    char searchName[30];
    cout << "\nNhap Ho ten can tim: ";
    cin.ignore(); // Loai bo ky tu new line trong buffer.
    cin.getline(searchName, sizeof(searchName));
    cout << endl << "Ket qua tim kiem theo Ho ten:" << endl;
    for (node *i = l.pHead; i != NULL; i = i->next)
    {
        // Sử dụng hàm strstr để kiểm tra xem searchName có tồn tại trong Họ tên của sinh viên không
        if (strstr(i->info.HoTen, searchName) != NULL)
        {
            Xuat(i->info);
        }
    }
    break;
    case 3:
        float searchScore;
        cout << "\nNhap Diem trung binh can tim: ";
        cin >> searchScore;
        cout << endl
             << "Ket qua tim kiem theo Diem trung binh:" << endl;
        for (node *i = l.pHead; i != NULL; i = i->next)
        {
            if (i->info.DTB == searchScore)
            {
                Xuat(i->info);
            }
        }
        break;
    default:
        cout << "Lua chon khong hop le. Vui long chon lai.\n";
    }
}

void Them(LIST &l)
{
    node *p, *r, *q;
    SV x;
    cout << "Nhap thong tin sinh vien can them:\n";
    Nhap(x);
    cout << "\nThem thanh cong.\n";
    p = makenode(x);

    if (l.pHead == NULL)
    {
        AddFirst(l, p);
        OutputList(l);
        return;
    }

    if (l.pHead->info.MSSV > x.MSSV)
    {
        AddFirst(l, p);
        OutputList(l);
        return;
    }

    if (l.pTail->info.MSSV < x.MSSV)
    {
        AddLast(l, p);
        OutputList(l);
        return;
    }

    r = l.pHead;
    q = l.pHead->next;

    while (q != NULL)
    {
        if (q->info.MSSV < x.MSSV)
        {
            r = q;
            q = q->next;
        }
        else
        {
            r->next = p;
            p->next = q;
            OutputList(l);
            return;
        }
    }
}

void Xoa(LIST &l)
{
    long long x;
    cout << "\nNhap MSSV can xoa: ";
    cin >> x;

    if (l.pHead == NULL)
    {
        cout << "\nDanh sach rong.";
        return;
    }

    if (l.pHead->info.MSSV == x)
    {
        cout << "Xoa thanh cong.\n";
        RemoveFirst(l);
        OutputList(l);
        return;
    }

    if (l.pTail->info.MSSV == x)
    {
        cout << "Xoa thanh cong.\n";
        RemoveLast(l);
        OutputList(l);
        return;
    }

    node *q = l.pHead->next;
    node *r = l.pHead;

    while (q != NULL)
    {
        if (q->info.MSSV == x)
        {
            r->next = q->next;
            delete q;
            cout << "Xoa thanh cong.\n";
            OutputList(l);
            return;
        }
        r = q;
        q = q->next;
    }

    cout << "Khong ton tai MSSV can xoa.\n";
}

void SapXepTheoDiemTrungBinh(LIST &l)
{
    if (l.pHead == NULL || l.pHead->next == NULL)
    {
        // Danh sach rong hoac chi co 1 phan tu, khong can sap xep.
        return;
    }

    node *p, *q;
    float temp;

    for (p = l.pHead; p != NULL; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->info.DTB > q->info.DTB)
            {
                // Hoan doi thong tin giua hai phan tu
                temp = p->info.DTB;
                p->info.DTB = q->info.DTB;
                q->info.DTB = temp;

                temp = p->info.MSSV;
                p->info.MSSV = q->info.MSSV;
                q->info.MSSV = temp;

                char tempName[30];
                strcpy(tempName, p->info.HoTen);
                strcpy(p->info.HoTen, q->info.HoTen);
                strcpy(q->info.HoTen, tempName);
            }
        }
    }
    cout << "DA SAP XEP THANH CONG ^-^" << endl;
}

int main()
{
    LIST l;
    init(l);
    int choice;

    while (true)
    {
        cout << "\n====== MENU ======\n";
        cout << "1. Nhap danh sach sinh vien\n";
        cout << "2. Xuat danh sach sinh vien\n";
        cout << "3. Tim kiem sinh vien\n";
        cout << "4. Them sinh vien\n";
        cout << "5. Xoa sinh vien\n";
        cout << "6: Sap xep theo diem trung binh\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            InputList(l);
            break;
        case 2:
            OutputList(l);
            break;
        case 3:
            TimKiem(l);
            break;
        case 4:
            Them(l);
            break;
        case 5:
            Xoa(l);
            break;
        case 6:
            SapXepTheoDiemTrungBinh(l);
            break;
        case 0:
            return 0;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
    }

    return 0;
}
