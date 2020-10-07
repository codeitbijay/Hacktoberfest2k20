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
            List<QueryParameter> lst = new List<QueryParameter>();
            QueryParameter l1 = new QueryParameter("client_id", "com.lr.applesignin");
            QueryParameter l2 = new QueryParameter("redirect_uri", "https://dev-hemant.devhub.lrinternal.com:443/socialauth/validate.sauth");
            QueryParameter l3 = new QueryParameter("response_type", "code");
            QueryParameter l4 = new QueryParameter("response_mode", "form_post");
            QueryParameter l = new QueryParameter("scope", "name email");
            lst.Add(l1);
            lst.Add(l2);
            lst.Add(l3);
            lst.Add(l4);
            lst.Add(l);
            Console.WriteLine(ToEncodedString(lst));
            Console.WriteLine(ToDecodedString(lst));
        }
        public static string ToEncodedString(List<QueryParameter> queryParameters)
        {
            var sb = new StringBuilder();
            foreach (var qp in queryParameters)
            {
                sb.Append("&").Append(HttpUtility.UrlEncode(qp.Key)).Append("=").Append(HttpUtility.UrlEncode(qp.Value));
            }
            return sb.ToString().Substring(1);
        }
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
