using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using champ_guide.Model;

namespace champ_guide.DataAccess
{
    public class champion_repo
    {
        readonly List<c_champion> _all_champions;

        public champion_repo()
        {
            if (_all_champions == null)
            {
                _all_champions = new List<c_champion>();
            }

            //_all_champions.Add(c_champion.CreateChampion("Zac"));
            //_all_champions.Add(c_champion.CreateChampion("Ahri"));
            //_all_champions.Add(c_champion.CreateChampion("Aatrox"));
            // go out into the internet and retrieve the champ list
            riot_api_interface.initialize();
            riot_api_interface.get_all_champions();
        }

        public List<c_champion> GetChampions()
        {
            return new List<c_champion>(_all_champions);
        }
    }
}
