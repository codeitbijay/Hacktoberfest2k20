using System;
using System.Collections.Generic;
using System.Text;

namespace URLEncodeDecode
{
    public class QueryParameter
    {
        private readonly string key;
        private string value;

        public QueryParameter(string key, string value)
        {
            this.key = key;
            this.value = value;
        }

        public string Key
        {
            get { return key; }
        }

        public string Value
        {
            get { return value; }
            set { this.value = value; }
        }
    }
}
