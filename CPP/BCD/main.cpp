#include <iostream>
#include "BCD.h"
#include <assert.h>
#include <climits>
using namespace std;

int main()
{
   int a = 125;
   int b = -975;
   
   BCD n = 12;
   cout << "Conver int to BCD: " << n << endl;
   cout << "Conver BCD to int: " << (int)n << endl;

   BCD n1;
   assert(n1 == BCD(0));
   cout << "convert 0 to = " << n1 << endl;

   BCD n2(a);
   cout << "Converted 125 (int) to " << n2 << " BCD" << endl;
   BCD n3(b);
   cout << "Converted -975 (int) to " << n3 << " BCD" << endl;

   BCD n4(n2);
   cout << "Converted 125 (int) to " << n4 << " BCD" << endl;

   BCD n5(n3);
   cout << "Converted -975 (int) to " << n5 << " BCD" << endl;
   n5 = n2;
   cout << "Converted -125 (int) to " << n5 << " BCD" << endl;

   BCD n6 = BCD("123456789012345678901234567890");
   cout << "Converted '123456789012345678901234567890' to " << n6 << " BCD" << endl;

   BCD n7 = BCD("123123123123123123123123123123");
   cout << "Converted '123123123123123123123123123123' to " << n7 << " BCD" << endl;

   cout << 125 << " type cast = " << (int)n2 << endl;
   cout << -975 << " type cast = " << (int)n3 << endl;

   assert((BCD() < BCD()) == false);
   assert((BCD(87) < BCD(200)) == true);
   assert((BCD(3456788) < BCD(3456789)) == true);
   assert((BCD() == BCD()) == true);
   assert((BCD(87) == BCD(2)) == false);
   assert((BCD(3456789) == BCD(3456789)) == true);
   assert((BCD(INT_MAX) == BCD(INT_MAX)) == true);

   //+
   cout << "+" << endl;
   cout << -77 << " + -100 (int) = " << (BCD(-77) + BCD(-100)) << endl;
   cout << -199999 << " + 1 (int) = " << (BCD(-199999) + BCD(1)) << endl;
   cout << INT_MIN << " + " << INT_MIN << " = " << (BCD(INT_MIN) + BCD(INT_MIN)) << endl;
   cout << INT_MAX << " + " << INT_MAX << " = " << (BCD(INT_MAX) + BCD(INT_MAX)) << endl;
   cout << 500000 << " + -1 (int) = " << (BCD(500000) + BCD(-1)) << endl;
   cout << 999 << " + 111 (int) = " << (BCD(999) + BCD(111)) << endl;
   cout << n6 << " + " << n7 << " = " << (BCD(n6) + BCD(n7)) << endl;

   assert((BCD(-121) + BCD(-121)) == BCD(-242));
   assert((BCD(-77) + BCD(-100)) == BCD(-177));
   assert((BCD(-199999) + BCD(1)) == BCD(-199998));
   assert((BCD(INT_MIN) + BCD(INT_MIN)) == BCD("-4294967296"));
   assert(((BCD(INT_MAX) + BCD(INT_MAX))) == BCD("4294967294"));
   assert((BCD(500000) + BCD(-1)) == BCD(499999));
   assert((BCD(555) + BCD(-111)) == BCD(444));
   assert((BCD(-555) + BCD(111)) == BCD(-444));
   assert((BCD(999) + BCD(111)) == BCD(1110));
   assert((BCD(0001) + BCD(0001)) == BCD(2));

   //-
   cout << " - " << endl;
   cout << -77 << " - -100 (int) = " << (BCD(-77) - BCD(-100)) << endl;
   cout << -199999 << " - 1 (int) = " << (BCD(-199999) - BCD(1)) << endl;
   cout << INT_MIN << " - " << INT_MIN << " = " << (BCD(INT_MIN) - BCD(INT_MIN)) << endl;
   cout << INT_MAX << " - " << INT_MAX << " = " << (BCD(INT_MAX) - BCD(INT_MAX)) << endl;
   cout << n6 << " - " << n7 << " = " << (BCD(n6) - BCD(n7)) << endl;

   assert((BCD(5000) - BCD(100)) == BCD(4900));
   assert((BCD(-77) - BCD(-100)) == BCD(23));
   assert((BCD(-199999) - BCD(1)) == BCD(-200000));
   assert((BCD(500000) - BCD(-1)) == BCD(500001));
   assert((BCD(0) - BCD(0)) == BCD(0));
   assert((BCD(0) - BCD(1)) == BCD(-1));
   assert((BCD(188) - BCD(99)) == BCD(89));
   assert((BCD(INT_MIN) - BCD(INT_MIN)) == BCD(0));
   assert((BCD(INT_MAX) - BCD(INT_MAX)) == BCD(0));

   // *
   cout << " * " << endl;
   cout << 11 << " * 10 (int) = " << (BCD(11) * BCD(10)) << endl;
   cout << -765 << " * 1 (int) = " << (BCD(-765) * BCD(1)) << endl;
   cout << 7 << " * -10 (int) = " << (BCD(7) * BCD(-10)) << endl;
   cout << 87654 << " * " << 5678 << " = " << (BCD(87654) * BCD(5678)) << endl;
   cout << INT_MAX << " * " << INT_MAX << " = " << (BCD(INT_MAX) * BCD(INT_MAX)) << endl;
   cout << INT_MAX/2 << " * " << (2) << " = " << (BCD(INT_MAX/2) * BCD(2)) << endl;
   cout << n6 << " * " << n7 << " = " << (BCD(n6) * BCD(n7)) << endl;

   assert((BCD(1234) * BCD(78)) == BCD(96252));
   assert((BCD(999) * BCD(99)) == BCD(98901));
   assert((BCD(1000) * BCD(10)) == BCD(10000));
   assert((BCD(10) * BCD(1000)) == BCD(10000));
   assert((BCD(111) * BCD(22)) == BCD(2442));
   assert((BCD(11) * BCD(10)) == BCD(110));
   assert((BCD(-765) * BCD(-10)) == BCD(7650));
   assert((BCD(765) * BCD(-10)) == BCD(-7650));
   assert((BCD(-765) * BCD(1)) == BCD(-765));
   assert((BCD(7) * BCD(-10)) == BCD(-70));
   assert((BCD(87654) * BCD(5678)) == BCD(497699412));

   //"/"
   cout << "/" << endl;
   cout << 7 << " / 70 (int) = " << (BCD(7) / BCD(70)) << endl;
   cout << -765 << " / 1 (int) = " << (BCD(-765) / BCD(1)) << endl;
   cout << INT_MAX << " / " << 1 << " = " << (BCD(INT_MAX) / BCD(1)) << endl;
   cout << INT_MAX << " / " << (INT_MAX/2) << " = " << (BCD(INT_MAX) / BCD((INT_MAX/2))) << endl;
   cout << INT_MAX << " / " << INT_MAX << " = " << (BCD(INT_MAX) / BCD(INT_MAX)) << endl;
   cout << INT_MIN << " / " << INT_MAX << " = " << (BCD(INT_MIN) / BCD(INT_MAX)) << endl;
   cout << 100 << " / " << 10 << " = " << (BCD(100) / BCD(10)) << endl;
   cout << 159836 << " / " << 124 << " = " << (BCD(159836) / BCD(124)) << endl;
   cout << 76500076 << " / " << 87 << " = " << (BCD(76500076) / BCD(87)) << endl;
   cout << n6 << " / " << n7 << " = " << (BCD(n6) / BCD(n7)) << endl;
   cout << BCD("1234567") << " / " << BCD("123") << " = " << (BCD("1234567") / BCD("123")) << endl;
   cout << BCD("123192739") << " / " << BCD("983") << " = " << (BCD("123192739") / BCD("983")) << endl;

   assert((BCD(7) / BCD(70)) == BCD(0));
   assert((BCD(-765) / BCD(1)) == BCD(-765));
   assert((BCD(INT_MAX) / BCD(1)) == BCD(INT_MAX));
   assert((BCD(INT_MAX) / BCD(INT_MAX / 2)) == BCD(2));
   assert((BCD(INT_MAX) / BCD(INT_MAX)) == BCD(1));
   assert((BCD(INT_MIN) / BCD(INT_MAX)) == BCD(-1));
   assert((BCD(100) / BCD(10)) == BCD(10));
   assert((BCD(159836) / BCD(124)) == BCD(1289));
   assert((BCD() / BCD(124)) == BCD(0));
   assert((BCD(1234567) / BCD(123)) == BCD(10037));
   assert((BCD(-123192739) / BCD(983)) == BCD(-125323));

   // <
   assert((BCD(159836) < BCD(124)) == false);
   assert((BCD(124) < BCD(159836)) == true);
   assert((BCD(-124) < BCD(-159836)) == false);

   // ==
   assert((BCD(-124) == BCD(-159836)) == false);
   assert((BCD(-124) == BCD(-124)) == true);
   assert((BCD(124) == BCD(124)) == true);
   assert((BCD(0) == BCD(0)) == true);

   //BCD n10;
   //cin >> n10;
   //cout << "Converted i/p (int) to " << n10 << " BCD" << endl;
   //cout << "i/p" << " type cast = " << (int)n10 << endl;

   return 0;
}
