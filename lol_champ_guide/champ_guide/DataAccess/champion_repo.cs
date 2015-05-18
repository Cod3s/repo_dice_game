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

            _all_champions.Add(c_champion.CreateChampion("Aatrox", "Some dude who fights things. This is going to be a super long description to try to determine how my UI will work with a super long string that hopefully will wrap. Of course I should try to just change the menu width, but that's too much work... jk"));           
            _all_champions.Add(c_champion.CreateChampion("Ahri", "Little miss Evee"));
            _all_champions.Add(c_champion.CreateChampion("Zac", "Giant Blob of awesome"));
                        
            // go out into the internet and retrieve the champ list
            //riot_api_interface.initialize();
            //riot_api_interface.get_all_champions();
        }

        public List<c_champion> GetChampions()
        {
            return new List<c_champion>(_all_champions);
        }
    }
}
