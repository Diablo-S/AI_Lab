// SHREYASH NEGI
// UE203113

// Clustering

#include <bits/stdc++.h>
using namespace std;

void printVec(vector<double> &v)
{
    for (auto a : v)
        cout << a << " ";
    cout << endl;
}

double mean(vector<double> &v)
{
    double s;
    for (auto a : v)
        s += a;

    s /= v.size();

    return s;
}

bool compare(double a, double b)
{
    if (abs(a - b) < 1e-9)
        return true;
    else
        return false;
}

int main()
{
    srand(time(0));

    vector<double> g1, g2, g3, g4;
    vector<double> list;

    double P, Q, R, S;
    cout << "Enter Seeds 1-4: ";

    cin >> P >> Q >> R >> S;
    cout << endl;

    g1.push_back(P);
    g2.push_back(Q);
    g3.push_back(R);
    g4.push_back(S);

    for (int i = 0; i < 100; i++)
        list.push_back((rand() % 100) + 1);

    cout << "List: ";
    printVec(list);
    cout << endl;

    for (int i = 0; i < 50; i++)
    {
        vector<double> s1, s2, s3, s4;
        s1.push_back(g1[i]);
        s2.push_back(g2[i]);
        s3.push_back(g3[i]);
        s4.push_back(g4[i]);

        for (auto l : list)
        {
            double a, b, c, d;
            double value;

            a = abs(s1[0] - l);
            b = abs(s2[0] - l);
            c = abs(s3[0] - l);
            d = abs(s4[0] - l);

            value = min(min(min(a, b), c), d);

            if (value == a)
            {
                s1.push_back(l);
                s1[0] = mean(s1);
            }
            else if (value == b)
            {
                s2.push_back(l);
                s2[0] = mean(s2);
            }
            else if (value == c)
            {
                s3.push_back(l);
                s3[0] = mean(s3);
            }
            else
            {
                s4.push_back(l);
                s4[0] = mean(s4);
            }
        }

        g1.push_back(s1[0]);
        g2.push_back(s2[0]);
        g3.push_back(s3[0]);
        g4.push_back(s4[0]);

        if (compare(g1[i + 1], g1[i]) && compare(g2[i + 1], g2[i]) && compare(g3[i + 1], g3[i]) && compare(g4[i + 1], g4[i]))
            break;
    }

    cout << "G1: ";
    printVec(g1);
    cout << endl;

    cout << "G2: ";
    printVec(g2);
    cout << endl;

    cout << "G3: ";
    printVec(g3);
    cout << endl;

    cout << "G4: ";
    printVec(g4);
    cout << endl;

    return 0;
}