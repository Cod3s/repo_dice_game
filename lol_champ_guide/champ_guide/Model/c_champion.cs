using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace champ_guide.Model
{
    public class c_champion
    {
        private List<c_champion_detail> _champion_details;

        public static c_champion CreateChampion(string name, string description)
        {
            c_champion creation = new c_champion
            {
                Name = name,
            };

            creation.add_detail("Name", name);
            creation.add_detail("Description", description);
            creation.add_detail("Starting Health", 100.0);

            return creation;
        }

        public List<c_champion_detail> ChampionDetails
        {
            get
            {
                if (_champion_details == null)
                {
                    _champion_details = new List<c_champion_detail>();
                }
                return _champion_details;
            }
        }

        private void add_detail(string label, object detail)
        {
            if (ChampionDetails.Any() && ChampionDetails.Where(a => a.Label == label).Any() == true)
            {
                // throw or notify here?
                return;
            }

            c_champion_detail to_add = new c_champion_detail(label, detail);
            _champion_details.Add(to_add);
        }

        public string Name { get; set; }

    }
}
