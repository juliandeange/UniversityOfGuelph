using System;
using System.Collections.Generic;

namespace BinaryStrings {
    class MainClass {
        public static void Main(string[] args) {

            int subString = 0;
            int zeroCount = 0;
            int totalZeroCount = 0;
            List<string> binaryStrings = new List<string>();

            Console.WriteLine("Enter binary string length N > 5");
            int start = Convert.ToInt32(Console.ReadLine()) - 1;
            int n = start + 1;
            double e = Math.Pow(2, start + 1);
            int end = Convert.ToInt32(e) - 1;

            //Converts integer to binary of length N 
            //Adds binary string to list
            for (int i = 0; i <= end; i++) {
                string temp = Convert.ToString(i, 2);

                while (temp.Length < n) {
                    temp = "0" + temp;
                }
                binaryStrings.Add(temp);
            }
            Console.WriteLine("-----");
            foreach (var str in binaryStrings) {
                Console.WriteLine(str);
                if (str.Contains("1010"))
                    subString++;

                for (int p = 0; p < str.Length; p++)
                    if (str[p] == '0')
                        zeroCount++;
                if (zeroCount >= 4)
                    totalZeroCount++;
                zeroCount = 0;
            }
            Console.WriteLine("-----");
            Console.WriteLine("Strings with 1010 = " + subString);
            Console.WriteLine("Strings with at least four 0s = " + totalZeroCount);
        }
    }
}

