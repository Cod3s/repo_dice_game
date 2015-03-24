using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace champ_guide.Model
{
    public class c_champion
    {
        public static c_champion CreateChampion(string name)
        {
            return new c_champion
            {
                Name = name
            };
        }

        public string Name { get; set; }
    }
}
