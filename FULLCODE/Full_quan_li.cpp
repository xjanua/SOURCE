#include <iostream>
#include <string.h>
using namespace std;

struct buu_kien
{
    unsigned int ma;
    string nguoi_gui;
    string nguoi_nhan;
    float kg;
    int ngay;
    int thang;
    int nam;
    string noi_dung;
    float gia;
};
typedef buu_kien buu_kien;

void nhap_so_luong(int *n)
{
    cout << endl
         << "Nhap so luong buu kien:";
    do
    {
        cin >> *n;
        if (*n < 0 || *n > 100)
        {
            cout << "Loi kich thuoc!" << endl
                 << "Vui long nhap lai:";
        }
    } while (*n < 0 || *n > 100);
}

bool kiem_tra_trung(buu_kien a[], int n, unsigned value)
{
    for (int i = 0; i < n; i++)
    {
        if (value == a[i].ma)
        {
            return true;
        }
    }
    return false;
}

void nhap_buu_kien(buu_kien a[], int n)
{
    unsigned int value;
    for (int i = 0; i < n; i++)
    {
        cout << "Bu kien thu " << i + 1 << ":" << endl;

        cout << "Nhap ma buu kien:";
        do
        {
            cin >> value;
            cin.ignore();
            if (kiem_tra_trung(a, n, value))
            {
                cout << "Ma buu kien da ton tai!" << endl
                     << "Nhap lai:";
            }
        } while (kiem_tra_trung(a, n, value));
        a[i].ma = value;

        cout << "Nhap ten nguoi gui:";
        getline(cin, a[i].nguoi_gui);

        cout << "Nhap ten nguoi nhan:";
        getline(cin, a[i].nguoi_nhan);

        cout << "Nhap trong luong:";
        cin >> a[i].kg;

        cout << "Nhap ngay gui:";
        cin >> a[i].ngay;
        cout << "Nhap thang:";
        cin >> a[i].thang;
        cout << "Nhap nam:";
        cin >> a[i].nam;
        cin.ignore();

        cout << "Nhap noi dung buu kien:";
        getline(cin, a[i].noi_dung);

        cout << "Nhap gia gui:";
        cin >> a[i].gia;
        cout << endl;
    }
}

void xuat_buu_kien(buu_kien a[], int n)
{
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "BUU KIEN THU " << i + 1 << ":" << endl;
        cout << "Ma buu kien: " << a[i].ma << endl;
        cout << "Ten nguoi gui: " << a[i].nguoi_gui << endl;
        cout << "Ten nguoi nhan: " << a[i].nguoi_nhan << endl;
        cout << "Trong luong buu kien: " << a[i].kg << endl;
        cout << "Ngay gui: " << a[i].ngay << "/" << a[i].thang << "/" << a[i].nam << endl;
        cout << "Noi dung buu kien: " << a[i].noi_dung << endl;
        cout << "Don gia gui: " << a[i].gia << endl;
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * " << endl;
    }
    cout << endl;
}

void them_buu_kien(buu_kien a[], int &n)
{
    unsigned int value;
    cout << endl;
    if (n > 100)
    {
        cout << "Khong the nhap them buu kien vi da het." << endl;
    }
    else
    {
        cout << "Nhap thong tin buu kien moi:" << endl;
        cout << "Nhap ma buu kien:";
        do
        {
            cin >> value;
            cin.ignore();
            if (kiem_tra_trung(a, n, value))
            {
                cout << "Ma buu kien da ton tai!" << endl
                     << "Nhap lai:";
            }
        } while (kiem_tra_trung(a, n, value));
        a[n].ma = value;

        cout << "Nhap ten nguoi gui:";
        getline(cin, a[n].nguoi_gui);

        cout << "Nhap ten nguoi nhan:";
        getline(cin, a[n].nguoi_nhan);

        cout << "Nhap trong luong:";
        cin >> a[n].kg;

        cout << "Nhap ngay gui:";
        cin >> a[n].ngay;
        cout << "Nhap thang:";
        cin >> a[n].thang;
        cout << "Nhap nam:";
        cin >> a[n].nam;
        cin.ignore();

        cout << "Nhap noi dung buu kien:";
        getline(cin, a[n].noi_dung);

        cout << "Nhap gia gui:";
        cin >> a[n].gia;
        cout << endl
             << "Buu kien da duoc them Thanh Cong ^-^." << endl;
        n++;
    }
}

void sep_ma(buu_kien a[], int n)
{
    buu_kien temp;
    buu_kien a_coppy[100];
    cout << "Da sap xep xong." << endl;
    for (int i = 0; i < n; i++)
    {
        a_coppy[i] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a_coppy[i].ma > a_coppy[j].ma)
            {
                temp = a_coppy[i];
                a_coppy[i] = a_coppy[j];
                a_coppy[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Buu kien thu " << i + 1 << " co ma: " << a_coppy[i].ma << endl;
    }
}

void Tinh_gia_tri(buu_kien a[], int n)
{
    cout << "Cong thuc tinh gia tri: Trong luong * Gia gui." << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Don hang ma so " << a[i].ma << " co gia: " << a[i].kg * a[i].gia << "$" << endl;
    }
    cout << endl;
}

int kg_max(buu_kien a[], int n)
{
    float Max = a[0].kg;
    for (int i = 0; i < n; i++)
    {
        if (a[i].kg > Max)
        {
            Max = a[i].kg;
        }
    }
    return Max;
}

void buu_kien_kg_max(buu_kien a[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].kg == kg_max(a, n))
        {
            dem++;
        }
    }
    cout << "Co " << dem << " buu kien co kg lon nhat!" << endl;
    for (int i = 0; i < n; i++)
    {
        if (a[i].kg == kg_max(a, n))
        {
            cout << "Ma buu kien: " << a[i].ma << endl;
        }
    }
    cout << "Deu co " << kg_max(a, n) << "kg" << endl;
}

void tim_buu_kien_name(buu_kien a[], int n)
{
    string find_name;
    int dem = 0;
    cout << "Tim buu kien theo ten nguoi gui!" << endl;
    cout << "Nhap ten nguoi gui:";
    cin.ignore();
    getline(cin, find_name);
    for (int i = 0; i < n; i++)
    {
        if (strcasecmp(a[i].nguoi_gui.c_str(), find_name.c_str()) == 0)
        {
            dem++;
        }
    }
    cout << "Co " << dem << " ket qua duoc tim thay:" << endl;
    for (int i = 0; i < n; i++)
    {
        if (strcasecmp(a[i].nguoi_gui.c_str(), find_name.c_str()) == 0)
        {
            cout << "Buu kien cua: " << a[i].nguoi_gui << endl;
            cout << "Ma so buu kien: " << a[i].ma << endl;
            cout << "*";
        }
    }
}

void t4_2014(buu_kien a[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].thang == 4 && a[i].nam == 2014)
        {
            dem++;
        }
    }
    if (dem == 0)
    {
        cout << "Khong tim thay buu kien!" << endl;
    }
    else
    {
        cout << "Co " << dem << " buu kien duoc tim thay:" << endl;
        for (int i = 0; i < n; i++)
        {
            if (a[i].thang == 4 && a[i].nam == 2014)
            {
                cout << "Buu kien cua " << a[i].nguoi_gui << " ma so buu kien: " << a[i].ma << endl;
            }
        }
    }
}
// Quản lí sinh vien;

struct SinhVien
{
    unsigned int mssv;
    string name;
    string gender;
    int day;
    int month;
    int year;
    ;
    string Class;
    float gpa;
};
typedef SinhVien Sv;
void enter_quantily(int *n)
{
    cout << "Nhap so luong sinh vien:";
    do
    {
        cin >> *n;
        if (*n < 0 || *n > 100)
        {
            cout << "Loi kich thuoc!" << endl
                 << "Nhap lai so luong:";
        }
    } while (*n < 0 || *n > 100);
    cin.ignore();
}

bool kt_trung_lap(Sv a[], int n, unsigned int value)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i].mssv == value)
        {
            return true;
        }
    }
    return false;
}

void enter_student(Sv a[], int n)
{
    unsigned int value;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap sinh vien thu " << i + 1 << ":" << endl;

        cout << "Nhap ten sinh vien:";
        getline(cin, a[i].name);

        do
        {
            cout << "Nhap ma so sinh vien:";
            cin >> value;
            cin.ignore();
            if (kt_trung_lap(a, n, value))
            {
                cout << "Ma so da ton tai!" << endl;
            }
        } while (kt_trung_lap(a, n, value));
        a[i].mssv = value;

        cout << "Gioi tinh(x:nam. y:nu): ";
        do
        {
            getline(cin, a[i].gender);
            if (a[i].gender != "x" && a[i].gender != "y")
            {
                cout << "Loi!" << endl
                     << "Nhap lai:";
            }
        } while (a[i].gender != "x" && a[i].gender != "y");

        cout << "Nhap ngay sinh:";
        cin >> a[i].day;
        cout << "Nhap thang sinh:";
        cin >> a[i].month;
        cout << "Nhap nam sinh:";
        cin >> a[i].year;
        cin.ignore();

        cout << "Hoc sinh lop:";
        getline(cin, a[i].Class);

        cout << "Nhap diem trung binh:";
        cin >> a[i].gpa;
        cin.ignore();
        cout << endl;
    }
    cout << endl;
}

void out_student(Sv a[], int n)
{
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Sinh vien " << i + 1 << ":" << endl;
        cout << "Ho va ten:" << a[i].name << endl;
        cout << "Mssv:" << a[i].mssv << endl;
        cout << "Gioi tinh:";
        if (a[i].gender == "x")
        {
            cout << "nam" << endl;
        }
        else if (a[i].gender == "y")
        {
            cout << "nu" << endl;
        }
        cout << "Ngay sinh:" << a[i].day << "/" << a[i].month << "/" << a[i].year << endl;
        cout << "Hoc sinh lop:" << a[i].Class << endl;
        cout << "Diem trung binh:" << a[i].gpa << endl;
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * " << endl;
    }
    cout << endl;
}

void out_gpa_above_5(Sv a[], int n)
{
    cout << "Cac sinh vien co GPA tren 5 la:" << endl;
    for (int i = 0; i < n; i++)
    {
        if (a[i].gpa > 5.0)
        {
            cout << "Sinh vien thu " << i + 1 << " "
                 << "ten: ";
            cout << a[i].name << endl;
        }
    }
    cout << endl;
}

void number_student_girl(Sv a[], int n)
{
    int sum = 0;
    cout << "So luong ban nu trong lop: ";
    for (int i = 0; i < n; i++)
    {
        if (a[i].gender == "y")
        {
            sum++;
        }
    }
    cout << sum << endl
         << endl;
}

void student_Max_gpa(Sv a[], int n)
{
    cout << "Sinh vien co gpa cao nhat la ";
    float Max = a[0].gpa;
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].gpa > Max)
        {
            Max = a[i].gpa;
            index = i;
        }
    }
    cout << "sinh vien thu " << index + 1 << " ten " << a[index].name << " voi gpa: " << Max;
    cout << endl
         << endl;
}

void add_new_student(Sv a[], int &n)
{
    unsigned int value;
    if (n >= 100)
    {
        cout << "You dont add new student because full list." << endl;
    }
    else
    {
        cout << "Nhap thong tin sinh vien can them." << endl;
        cout << "Nhap ten sinh vien:";
        getline(cin, a[n].name);

        do
        {
            cout << "Nhap ma so sinh vien:";
            cin >> value;
            cin.ignore();
            if (kt_trung_lap(a, n, value))
            {
                cout << "Ma so da ton tai!" << endl;
            }
        } while (kt_trung_lap(a, n, value));
        a[n].mssv = value;

        cout << "Gioi tinh(x:nam. y:nu): ";
        do
        {
            getline(cin, a[n].gender);
            if (a[n].gender != "x" && a[n].gender != "y")
            {
                cout << "Loi!" << endl
                     << "Nhap lai:";
            }
        } while (a[n].gender != "x" && a[n].gender != "y");

        cout << "Nhap ngay sinh:";
        cin >> a[n].day;
        cout << "Nhap thang sinh:";
        cin >> a[n].month;
        cout << "Nhap nam sinh:";
        cin >> a[n].year;
        cin.ignore();

        cout << "Hoc sinh lop:";
        getline(cin, a[n].Class);

        cout << "Nhap diem trung binh:";
        cin >> a[n].gpa;
        cin.ignore();
        n++;
        cout << endl
             << "Sinh vien da duoc them!" << endl;
    }
}

void find_and_delete(Sv a[], int &n)
{
    unsigned x;
    cout << "Nhap mssv de xoa sinh vien:";
    cin >> x;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (x == a[i].mssv)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        cout << "Sinh vien khong duoc tim thay!" << endl;
    }
    else
    {
        cout << "Sinh vien thu " << index + 1 << " ten " << a[index].name << "." << endl;
        for (int i = index; i < n - 1; i++)
        {
            a[i] = a[i + 1];
        }
        n--;
        cout << "Sinh vien da duoc xoa THANH CONG." << endl
             << endl;
    }
}

void sap_xep_gpa(Sv a[], int n)
{
    cout << "Sau khi sap xep ta duoc." << endl;
    Sv temp;
    Sv a_coppy[100];
    for (int i = 0; i < n; i++)
    {
        a_coppy[i] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a_coppy[i].gpa < a_coppy[j].gpa)
            {
                temp = a_coppy[i];
                a_coppy[i] = a_coppy[j];
                a_coppy[j] = temp;
            }
        }
    }
    // Xuất danh sách gpa từ cao xuống thấp
    for (int i = 0; i < n; i++)
    {
        cout << "Sinh vien gpa cao thu " << i + 1 << " ten " << a_coppy[i].name << " co gpa " << a_coppy[i].gpa << "." << endl;
    }
}

struct thue_bao
{
    unsigned int ma;
    string chu_thue_bao;
    int ngay;
    int thang;
    int nam;
    string sdt;
    int loai_thue_bao;
    unsigned int tg_noi_mang;
    unsigned int tg_ngoai_mang;
};
typedef thue_bao thue_bao;

void nhap_sl(int *n)
{
    cout << "Nhap so luong thue bao:";
    do
    {
        cin >> *n;
        if (*n < 0 || *n > 100)
        {
            cout << "Loi so luong!" << endl;
            cout << "Nhap lai:";
        }
    } while (*n < 0 || *n > 100);
}

bool kiem_tra_trung_lap(thue_bao a[], int n, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i].ma == value)
        {
            return true;
        }
    }
    return false;
}

void nhap_thue_bao(thue_bao a[], int n)
{
    unsigned int value;
    for (int i = 0; i < n; i++)
    {
        cout << "Thue bao " << i + 1 << endl;
        cout << "Nhap ma thue bao: ";
        do
        {
            cin >> value;
            cin.ignore();
            if (kiem_tra_trung_lap(a, n, value))
            {
                cout << "Da ton tai ma thue bao!" << endl
                     << "Vui long nhap lai:";
            }
        } while (kiem_tra_trung_lap(a, n, value));
        a[i].ma = value;

        cout << "Nhap chu thue bao:";
        getline(cin, a[i].chu_thue_bao);

        cout << "Nhap ngay:";
        cin >> a[i].ngay;
        cout << "Nhap thang:";
        cin >> a[i].thang;
        cout << "Nhap nam:";
        cin >> a[i].nam;

        cout << "Nhap so dien thoai:";
        cin.ignore();
        getline(cin, a[i].sdt);

        cout << "(1: tra truoc)" << endl
             << "(2: tra sau)" << endl
             << "Nhap loai thue bao:";
        do
        {
            cin >> a[i].loai_thue_bao;
            if (a[i].loai_thue_bao < 1 || a[i].loai_thue_bao > 2)
            {
                cout << "Loi!" << endl
                     << "Nhap lai:";
            }
        } while (a[i].loai_thue_bao < 1 || a[i].loai_thue_bao > 2);

        cout << "Thoi gian goi noi mang.(Minute):";
        cin >> a[i].tg_noi_mang;

        cout << "Thoi gian goi ngoai mang.(Minute):";
        cin >> a[i].tg_ngoai_mang;
        cout << endl;
    }
}

void xuat_thong_tin_tb(thue_bao a[], int n)
{
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Thue bao thu " << i + 1 << "." << endl;
        cout << "Ma thue bao: " << a[i].ma << endl;
        cout << "Chu thue bao: " << a[i].chu_thue_bao << endl;
        cout << "Ngay dang ki thue bao: " << a[i].ngay << "/" << a[i].thang << "/" << a[i].nam << "." << endl;
        cout << "So dien thoai: " << a[i].sdt << endl;
        cout << "Loai thue bao: ";
        if (a[i].loai_thue_bao == 1)
        {
            cout << "Tra truoc." << endl;
        }
        else if (a[i].loai_thue_bao == 2)
        {
            cout << "Tra sau." << endl;
        }
        cout << "Thoi gian goi noi mang: " << a[i].tg_noi_mang << " phut." << endl;
        cout << "Thoi gian goi ngoai mang: " << a[i].tg_ngoai_mang << " phut." << endl;
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * " << endl;
    }
    cout << endl;
}

void them_thue_bao(thue_bao a[], int &n)
{
    unsigned int value;
    cout << "THEM THUE BAO MOI." << endl;
    cout << "Nhap ma thue bao: ";
    do
    {
        cin >> value;
        cin.ignore();
        if (kiem_tra_trung_lap(a, n, value))
        {
            cout << "Da ton tai ma thue bao!" << endl
                 << "Vui long nhap lai:";
        }
    } while (kiem_tra_trung_lap(a, n, value));
    a[n].ma = value;

    cout << "Nhap chu thue bao:";
    getline(cin, a[n].chu_thue_bao);

    cout << "Nhap ngay:";
    cin >> a[n].ngay;
    cout << "Nhap thang:";
    cin >> a[n].thang;
    cout << "Nhap nam:";
    cin >> a[n].nam;

    cout << "Nhap so dien thoai:";
    cin.ignore();
    getline(cin, a[n].sdt);

    cout << "(1: tra truoc)" << endl
         << "(2: tra sau)" << endl
         << "Nhap loai thue bao:";
    do
    {
        cin >> a[n].loai_thue_bao;
        if (a[n].loai_thue_bao < 1 || a[n].loai_thue_bao > 2)
        {
            cout << "Loi!" << endl
                 << "Nhap lai:";
        }
    } while (a[n].loai_thue_bao < 1 || a[n].loai_thue_bao > 2);

    cout << "Thoi gian goi noi mang.(Minute):";
    cin >> a[n].tg_noi_mang;

    cout << "Thoi gian goi ngoai mang.(Minute):";
    cin >> a[n].tg_ngoai_mang;
    cout << "DA THEM THUE BAO THANH CONG^-^" << endl;
    n++;
    cout << endl;
}

void sap_xep(thue_bao a[], int n)
{
    thue_bao a_coppy[100];
    thue_bao temp;
    for (int i = 0; i < n; i++)
    {
        a_coppy[i] = a[i];
    }
    cout << "Sap xep ma so thue bao THANH CONG." << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a_coppy[i].ma > a_coppy[j].ma)
            {
                temp = a_coppy[i];
                a_coppy[i] = a_coppy[j];
                a_coppy[j] = temp;
            }
        }
    }
    // xuat
    for (int i = 0; i < n; i++)
    {
        cout << "Ma thue bao " << i + 1 << ": " << a_coppy[i].ma << "." << endl;
    }
}

void tim_thue_bao(thue_bao a[], int n)
{
    string find_name;
    int dem = 0;
    cout << "Tim thue bao theo ten chu thue bao!" << endl;
    cout << "Nhap chu thue bao:";
    getline(cin, find_name);
    for (int i = 0; i < n; i++)
    {
        if (strcasecmp(a[i].chu_thue_bao.c_str(), find_name.c_str()) == 0)
        {
            dem++;
        }
    }
    cout << "Co " << dem << " ket qua duoc tim thay." << endl;
    for (int i = 0; i < n; i++)
    {
        if (strcasecmp(a[i].chu_thue_bao.c_str(), find_name.c_str()) == 0)
        {
            cout << i + 1 << ": " << a[i].chu_thue_bao << "." << endl;
            cout << "Ma so thue bao: " << a[i].ma << endl;
        }
    }
}

void xuat_thue_bao_theo_loai(thue_bao a[], int n)
{
    int loai_thue_bao;
    int dem1 = 0;
    int dem2 = 0;
    cout << "Ban muon tim kiem loai thue bao: " << endl;
    cout << "1:Tra truoc." << endl;
    cout << "2:Tra sau." << endl;
    cout << "Moi ban nhap:";
    do
    {
        cin >> loai_thue_bao;
        if (loai_thue_bao < 1 || loai_thue_bao > 2)
        {
            cout << "Loi!" << endl;
            cout << "Nhap lai:";
        }
    } while (loai_thue_bao < 1 || loai_thue_bao > 2);
    switch (loai_thue_bao)
    {
    case 1:
        for (int i = 0; i < n; i++)
        {
            if (loai_thue_bao == a[i].loai_thue_bao)
            {
                dem1++;
            }
        }
        cout << "Co " << dem1 << " ket qua duoc tim thay." << endl;
        for (int i = 0; i < n; i++)
        {
            if (loai_thue_bao == a[i].loai_thue_bao)
            {
                cout << i + 1 << ".Ma thue bao: " << a[i].ma << endl;
            }
        }
        break;

    case 2:
        for (int i = 0; i < n; i++)
        {
            if (loai_thue_bao == a[i].loai_thue_bao)
            {
                dem2++;
            }
        }
        cout << "Co " << dem2 << " ket qua duoc tim thay." << endl;
        for (int i = 0; i < n; i++)
        {
            if (loai_thue_bao == a[i].loai_thue_bao)
            {
                cout << i + 1 << ".Ma thue bao: " << a[i].ma << endl;
            }
        }
        break;
    }
}

void xuat_thue_bao_sau_2010(thue_bao a[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].nam > 2010)
        {
            dem++;
        }
    }
    cout << "Co " << dem << " ket qua duoc tim thay." << endl;
    for (int i = 0; i < n; i++)
    {
        if (a[i].nam > 2010)
        {
            cout << i + 1 << ".Ma thue bao: " << a[i].ma << endl;
        }
    }
}

void gia_cuoc(thue_bao a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Khach hang " << a[i].chu_thue_bao << ": " << a[i].ma << endl;
        cout << "Noi mang: " << 1500 * a[i].tg_noi_mang << " nghin dong." << endl;
        cout << "Ngoai mang:" << 3000 * a[i].tg_ngoai_mang << " nghin dong." << endl
             << endl;
    }
}

void sl_tb_tt(thue_bao a[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].loai_thue_bao == 1)
        {
            dem++;
        }
    }
    cout << "Co " << dem << " thue bao tra truoc." << endl;
}

struct quanlisach
{
    unsigned int ma;
    string ten_sach;
    string tac_gia;
    int loai_sach;
    unsigned int nam_xuat_ban;
    unsigned int gia_tien;
    unsigned int so_luong;
};
typedef quanlisach qlsach;

void nhap_sl_sach(int *n)
{
    cout << "Nhap so luong sach:";
    do
    {
        cin >> *n;
        if (*n < 0 || *n > 100)
        {
            cout << "Loi kich thuoc!" << endl
                 << "Nhap lai:";
        }
    } while (*n < 0 || *n > 100);
}

bool kt_trung_lap(qlsach a[], int n, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i].ma == value)
        {
            return true;
        }
    }
    return false;
}

void nhap_sach(qlsach a[], int n)
{
    unsigned int value;
    for (int i = 0; i < n; i++)
    {
        cout << "Quyen sach " << i + 1 << "." << endl;
        cout << "Nhap ma sach: ";
        do
        {
            cin >> value;
            cin.ignore();
            if (kt_trung_lap(a, n, value))
            {
                cout << "Da ton tai!" << endl
                     << "Nhap la ma so sach: ";
            }
        } while (kt_trung_lap(a, n, value));
        a[i].ma = value;

        cout << "Nhap ten sach:";
        getline(cin, a[i].ten_sach);

        cout << "Nhap ten tac gia: ";
        getline(cin, a[i].tac_gia);

        cout << "1. Sach tu nhien." << endl;
        cout << "2. Sach xa hoi." << endl;
        cout << "Nhap loai sach: ";
        do
        {
            cin >> a[i].loai_sach;
            if (a[i].loai_sach < 1 || a[i].loai_sach > 2)
            {
                cout << "Sai cu phap." << endl
                     << "Nhap lai: ";
            }
        } while (a[i].loai_sach < 1 || a[i].loai_sach > 2);

        cout << "Nhap nam xuat ban: ";
        cin >> a[i].nam_xuat_ban;

        cout << "Nhap gia tien: ";
        cin >> a[i].gia_tien;

        cout << "Nhap so luong: ";
        cin >> a[i].so_luong;
        cout << endl;
    }
}

void xuat_thong_tin(qlsach a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Quyen sach " << i + 1 << "." << endl;
        cout << "Ma sach: " << a[i].ma << endl;
        cout << "Ten sach: " << a[i].ten_sach << endl;
        cout << "Tac gia: " << a[i].tac_gia << endl;
        cout << "Loai sach: ";
        if (a[i].loai_sach == 1)
        {
            cout << "tu nhien." << endl;
        }
        else if (a[i].loai_sach == 2)
        {
            cout << "xa hoi." << endl;
        }
        cout << "Nam xuat ban: " << a[i].nam_xuat_ban << endl;
        cout << "Gia tien: " << a[i].gia_tien << endl;
        cout << "So luong: " << a[i].so_luong << endl;
        cout << endl;
    }
}

void them_sach(qlsach a[], int &n)
{
    unsigned int value;
    cout << "Nhap ma sach: ";
    do
    {
        cin >> value;
        cin.ignore();
        if (kt_trung_lap(a, n, value))
        {
            cout << "Da ton tai!" << endl
                 << "Nhap la ma so sach: ";
        }
    } while (kt_trung_lap(a, n, value));
    a[n].ma = value;

    cout << "Nhap ten sach:";
    getline(cin, a[n].ten_sach);

    cout << "Nhap ten tac gia: ";
    getline(cin, a[n].tac_gia);

    cout << "1. Sach tu nhien." << endl;
    cout << "2. Sach xa hoi." << endl;
    cout << "Nhap loai sach: ";
    do
    {
        cin >> a[n].loai_sach;
        if (a[n].loai_sach < 1 || a[n].loai_sach > 2)
        {
            cout << "Sai cu phap." << endl
                 << "Nhap lai: ";
        }
    } while (a[n].loai_sach < 1 || a[n].loai_sach > 2);

    cout << "Nhap nam xuat ban: ";
    cin >> a[n].nam_xuat_ban;

    cout << "Nhap gia tien: ";
    cin >> a[n].gia_tien;

    cout << "Nhap so luong: ";
    cin >> a[n].so_luong;
    cout << endl
         << "DA THEM SACH THANH CONG!" << endl;
    n++;
}

void tinh_tong_tien(qlsach a[], int n)
{
    int tong = 0;
    cout << "Tong tien cac cuon sach la: ";
    for (int i = 0; i < n; i++)
    {
        tong = tong + (a[i].so_luong * a[i].gia_tien);
    }
    cout << tong << endl;
}

void sap_xep_ma_sach(qlsach a[], int n)
{
    cout << "DA XEP THANH CONG." << endl;
    qlsach a_coppy[100];
    qlsach temp;
    for (int i = 0; i < n; i++)
    {
        a_coppy[i] = a[i];
    }
    // Sap xep;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a_coppy[i].ma > a_coppy[j].ma)
            {
                temp = a_coppy[i];
                a_coppy[i] = a_coppy[j];
                a_coppy[j] = temp;
            }
        }
    }
    // xuat
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ": " << a_coppy[i].ten_sach << endl;
        cout << "Ma sach: " << a_coppy[i].ma << endl;
        cout << endl;
    }
}

void tim_sach(qlsach a[], int n)
{
    int dem = 0;
    string find;
    cout << "Nhap ten sach:";
    getline(cin, find);
    for (int i = 0; i < n; i++)
    {
        if (strcasecmp(a[i].ten_sach.c_str(), find.c_str()) == 0)
        {
            dem++;
        }
    }
    cout << "Co " << dem << " ket qua duoc tim thay:" << endl;
    for (int i = 0; i < n; i++)
    {
        if (strcasecmp(a[i].ten_sach.c_str(), find.c_str()) == 0)
        {
            cout << i + 1 << ": " << a[i].ten_sach << endl
                 << "Ma so: " << a[i].ma << endl;
            cout << "*";
        }
    }
}

void xuat_truoc_2000(qlsach a[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].nam_xuat_ban < 2000)
        {
            dem++;
        }
    }
    cout << "Co " << dem << " ket qua duoc tim thay." << endl;
    for (int i = 0; i < n; i++)
    {
        if (a[i].nam_xuat_ban < 2000)
        {
            cout << "Quyen sach " << a[i].ten_sach << " duoc xuat ban nam: " << a[i].nam_xuat_ban << endl;
        }
    }
}

void sl_sach_tren_50000(qlsach a[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].gia_tien > 50000)
        {
            dem++;
        }
    }
    cout << "Co " << dem << " cuon sach gia tren 50000." << endl;
}

void xuat_loai_sach(qlsach a[], int n)
{
    int chon;
    cout << "1. Sach tu nhien." << endl;
    cout << "2. Sach xa hoi." << endl;
    cout << "* * * *" << endl;
    cout << "Nhap loai sach.";
    do
    {
        cin >> chon;
        if (chon < 1 || chon > 2)
        {
            cout << "Sai cu phap." << endl
                 << "Nhap lai: ";
        }
    } while (chon < 1 || chon > 2);
    switch (chon)
    {
    case 1:
        for (int i = 0; i < n; i++)
        {
            if (a[i].loai_sach == 1)
            {
                cout << a[i].ten_sach << endl;
            }
        }
        break;
    case 2:
        for (int i = 0; i < n; i++)
        {
            if (a[i].loai_sach == 2)
            {
                cout << a[i].ten_sach << endl;
            }
        }
    }
}

void menu_quan_li_sinh_vien()
{
    Sv a[100];
    int choice;
    int n;
    enter_quantily(&n);
    enter_student(a, n);
    while (1)
    {
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * " << endl;
        cout << "\t* * * * * M * E * N * U * * * * * *" << endl;
        cout << "0: Thoat" << endl;
        cout << "1: Xuat danh sach sinh vien." << endl;
        cout << "2: Cac sinh vien co gpa above 5." << endl;
        cout << "3: So luong sinh vien girl." << endl;
        cout << "4: Sinh vien co gpa max." << endl;
        cout << "5: Them sinh vien moi." << endl;
        cout << "6: Xoa sinh vien." << endl;
        cout << "7: Sap xep sinh vien theo gpa." << endl;
        cout << "Nhap lua chon cua ban:";
        do
        {
            cin >> choice;
            cin.ignore();
            if (choice < 1 || choice > 7)
            {
                cout << "Khong hop le!" << endl;
                cout << "Nhap lai:";
            }
        } while (choice < 0 || choice > 7);
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * " << endl
             << endl;
        switch (choice)
        {
        case 0:
            return;

        case 1:
            out_student(a, n);
            break;

        case 2:
            out_gpa_above_5(a, n);
            break;

        case 3:
            number_student_girl(a, n);
            break;

        case 4:
            student_Max_gpa(a, n);
            break;

        case 5:
            add_new_student(a, n);
            break;

        case 6:
            find_and_delete(a, n);
            break;

        case 7:
            sap_xep_gpa(a, n);
            break;
        }
    }
}

void menu_quan_li_buu_kien()
{
    int choice;
    int n;
    buu_kien a[100];
    nhap_so_luong(&n);
    nhap_buu_kien(a, n);
    while (1)
    {
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * " << endl;
        cout << "\t* * * * * M * E * N * U * * * * * *" << endl;
        cout << "0: Thoat" << endl;
        cout << "1: Xuat danh sach buu kien." << endl;
        cout << "2: Them buu kien moi." << endl;
        cout << "3: Sap xep buu kien theo ma tu be den lon." << endl;
        cout << "4: Tinh gia don hang." << endl;
        cout << "5: So luong buu kien co kg Max." << endl;
        cout << "6: Tim buu kien." << endl;
        cout << "7: Tim buu kien thang 4 nam 2014." << endl;
        cout << "Nhap lua chon cua ban:";
        do
        {
            cin >> choice;
            if (choice < 0 || choice > 8)
            {
                cout << "Khong hop le!" << endl
                     << "Vui long Nhap lai:";
            }
        } while (choice < 0 || choice > 8);
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * " << endl
             << endl;
        switch (choice)
        {
        case 0:
            return;

        case 1:
            xuat_buu_kien(a, n);
            break;

        case 2:
            them_buu_kien(a, n);
            break;

        case 3:
            sep_ma(a, n);
            break;

        case 4:
            Tinh_gia_tri(a, n);
            break;

        case 5:
            buu_kien_kg_max(a, n);
            break;

        case 6:
            tim_buu_kien_name(a, n);
            break;

        case 7:
            t4_2014(a, n);
            break;
        }
    }
}

void menu_quan_li_thue_bao()
{
    thue_bao a[100];
    int choice;
    int n;
    nhap_sl(&n);
    nhap_thue_bao(a, n);
    while (1)
    {
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * " << endl;
        cout << "\t* * * * * M * E * N * U * * * * * *" << endl;
        cout << "0: Thoat" << endl;
        cout << "1: Xuat danh sach thue bao." << endl;
        cout << "2: Them 1 thue bao moi." << endl;
        cout << "3: Sap xep danh sach theo ma thue bao." << endl;
        cout << "4: Tim thue bao." << endl;
        cout << "5: Xuat loai thue bao." << endl;
        cout << "6: Xuat thue bao dang ki sau 2010." << endl;
        cout << "7: Tinh cuoc phi thue bao." << endl;
        cout << "8: Dem so luong thue bao tra truoc." << endl;
        cout << "Nhap lua chon cua ban:";
        do
        {
            cin >> choice;
            cin.ignore();
            if (choice < 0 || choice > 8)
            {
                cout << "Khong hop le!" << endl;
                cout << "Nhap lai:";
            }
        } while (choice < 0 || choice > 8);
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * " << endl
             << endl;
        switch (choice)
        {
        case 0:
            return;

        case 1:
            xuat_thong_tin_tb(a, n);
            break;

        case 2:
            them_thue_bao(a, n);
            break;

        case 3:
            sap_xep(a, n);
            break;

        case 4:
            tim_thue_bao(a, n);
            break;

        case 5:
            xuat_thue_bao_theo_loai(a, n);
            break;

        case 6:
            xuat_thue_bao_sau_2010(a, n);
            break;

        case 7:
            gia_cuoc(a, n);
            break;

        case 8:
            sl_tb_tt(a, n);
            break;
        }
    }
}

void menu_quan_li_sach()
{
    qlsach a[100];
    int choice;
    int n;
    nhap_sl_sach(&n);
    nhap_sach(a, n);
    while (1)
    {
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * " << endl;
        cout << "\t* * * * * M * E * N * U * * * * * *" << endl;
        cout << "0: Thoat" << endl;
        cout << "1: Xuat thong tin." << endl;
        cout << "2: Nhap them 1 quyen sach." << endl;
        cout << "3: Tinh tong tien tat ca cuon sach." << endl;
        cout << "4: Sap xep sach theo ma." << endl;
        cout << "5: Tim sach." << endl;
        cout << "6: Sach xuat ban truoc nam 2000." << endl;
        cout << "7: So luong sach tren 50000." << endl;
        cout << "8: Xuat loai sach." << endl;
        cout << "Nhap lua chon cua ban:";
        do
        {
            cin >> choice;
            cin.ignore();
            if (choice < 0 || choice > 8)
            {
                cout << "Khong hop le!" << endl;
                cout << "Nhap lai:";
            }
        } while (choice < 0 || choice > 8);
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * " << endl
             << endl;
        switch (choice)
        {
        case 0:
            return;

        case 1:
            xuat_thong_tin(a, n);
            break;

        case 2:
            them_sach(a, n);
            break;

        case 3:
            tinh_tong_tien(a, n);
            break;

        case 4:
            sap_xep_ma_sach(a, n);
            break;

        case 5:
            tim_sach(a, n);
            break;

        case 6:
            xuat_truoc_2000(a, n);
            break;

        case 7:
            sl_sach_tren_50000(a, n);
            break;

        case 8:
            xuat_loai_sach(a, n);
            break;
        }
    }
}

void menu_tong()
{
    int choice;
    cout << "* * * * * * * * * * * * * * * * * * * * " << endl;
    cout << "0: Quay lai" << endl;
    cout << "1: Chuong trinh quan li sinh vien." << endl;
    cout << "2: Quan li buu kien." << endl;
    cout << "3: Quan li thue bao dien thoai." << endl;
    cout << "4: Quan li sach." << endl;
    cout << "Nhap lua chon cua ban:";
    do
    {
        cin >> choice;
        if (choice < 0 || choice > 4)
        {
            cout << "Khong hop le!" << endl
                 << "Vui long Nhap lai:";
        }
        cout << "* * * * * * * * * * * * * * * * * * * * " << endl;
    } while (choice < 0 || choice > 4);
    switch (choice)
    {
    case 0:
        menu_tong();
        break;

    case 1:
        menu_quan_li_sinh_vien();
        break;

    case 2:
        menu_quan_li_buu_kien();
        break;

    case 3:
        menu_quan_li_thue_bao();
        break;

    case 4:
        menu_quan_li_sach();
        break;
    }
}

int main()
{
    menu_tong();
    return 1;
}
// NKT