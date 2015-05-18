using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace champ_guide.Model
{
    public class c_champion_detail
    {
        public c_champion_detail(string label, object detail)
        {
            Label = label;
            Detail = detail;
        }

        public string Label { get; set; }


        public object Detail { get; set; }
    }
}
