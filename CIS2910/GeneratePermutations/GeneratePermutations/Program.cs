using System;
using System.Collections.Generic;
using System.Linq;

namespace GeneratePermutations {
    class MainClass {
        public static void Main(string[] args) {

            int num = Convert.ToInt32(Console.ReadLine());
            int totalPermutations = 0;
            List<int> n = new List<int>(); //stores the string 1,2, ..., n
            List<int> nsub = new List<int>(); //stores numbers before decrease in sequence
            List<int> original = new List<int>(); //copy of original sequence
            int isdis = 1;
            int derangement = 0;

            foreach (var v in n) Console.Write(v);
            for (int i = 1; i <= num; i++) {
                n.Add(i);
                original.Add(i);
            }
            int factorial = 1;
            for (int i = num; i > 0; i--)  //calculates the factorial of permutations
                factorial = factorial * i;
            foreach (var v in n) Console.Write(v);
            for (int y = 0; y < factorial; y++) {
                n.Reverse();
                Console.WriteLine();
                for (int i = 0; i < n.Count - 1; i++) { //Looks for decrease in sequence
                    nsub.Add(n[i]);
                    if (n[i] > n[i + 1]) {
                        int toSwap = n[i + 1];
                        int toReplace = nsub.Where(l => l > n[i + 1]).Min();
                        n[i + 1] = toReplace;  //replaces decreased value with largest min number
                        nsub.Remove(toReplace);
                        nsub.Add(toSwap);
                        nsub = nsub.OrderByDescending(p => p).ToList();

                        //******SUB IN NSUB OT BEGINNING OF N*****
                        for (int p = 0; p < nsub.Count(); p++)  //re-orders lowest to highest
                            n[p] = nsub[p];
                        n.Reverse();
                        nsub.Clear();

                        for (int o = 0; o < n.Count; o++){ //checks for disrangements by seeing if every value..
                            if (original[o] != n[o]) {     //   ..is not the original 
                                isdis = 1;
                                continue;
                            }
                            if (original[o] == n[o]) {
                                isdis =  0;
                                break;
                            } 
                        }
                        if (isdis == 1) {
                            derangement++; //counts disrangements
                            Console.Write("*");
                        }
                        isdis = 0;
                        foreach (var v in n) Console.Write(v);
                        break;
                    }//end if
                }//end inner (for) looking through letters
                totalPermutations++;
            }//end (for) factorial counter
            Console.WriteLine("total perms = " + totalPermutations);
            Console.WriteLine("disarrangements = " + derangement);
            double prob = Convert.ToDouble(derangement) / Convert.ToDouble(totalPermutations);
            Console.WriteLine("probability of derangement = " + prob);
        }//end main
    }//end class
}//end namespace
