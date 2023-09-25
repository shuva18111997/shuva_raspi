using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApplication1
{
    class DaoPojo
    {
        public static string name { get; set; }
        public static int roll { get; set; }
        public static string dept { get; set; }
        public static int year { get; set; }
        public static string date { get; set; }
        public static string NewDate()
        {
            string Date = "";
            char splitchar = '/';
            string[] strArr = date.Split(splitchar);// 03/10/2018 --> 2018-03-10
            Date = strArr[2] + "-" + strArr[0] + "-" + strArr[1];
            return Date;
        }
    }
}
