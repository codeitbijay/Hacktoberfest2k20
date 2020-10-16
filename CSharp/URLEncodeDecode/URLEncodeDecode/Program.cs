using System;
using System.Collections.Generic;
using System.Text;
using System.Web;

namespace URLEncodeDecode
{
    class Program
    {
        static void Main(string[] args)
        {
            string Url = "https://google.com?";
            //Taking parameter as a key value pair that will help building the encoded URL
            List<QueryParameter> queryParam = new List<QueryParameter>
            {
                new QueryParameter("redirect_url", "https://xyz.com"),
                new QueryParameter("apiKey","123456")
            };
            Console.WriteLine(Url+ToEncodedString(queryParam));
            Console.WriteLine(Url+ToDecodedString(queryParam));
        }
        //Encoded URL string method
        //If there are multiple parameters than they are appended with the '&'
        public static string ToEncodedString(List<QueryParameter> queryParameters)
        {
            var sb = new StringBuilder();
            foreach (var qp in queryParameters)
            {
                sb.Append("&").Append(HttpUtility.UrlEncode(qp.Key)).Append("=").Append(HttpUtility.UrlEncode(qp.Value));
            }
            return sb.ToString().Substring(1);
        }
        //Decoded URL string method
        //If there are multiple parameters than they are appended with the '&'
        public static string ToDecodedString(List<QueryParameter> queryParameters)
        {
            var sb = new StringBuilder();
            foreach (var qp in queryParameters)
            {
                sb.Append("&").Append(HttpUtility.UrlDecode(qp.Key)).Append("=").Append(HttpUtility.UrlDecode(qp.Value));
            }
            return sb.ToString().Substring(1);
        }
    }
}
