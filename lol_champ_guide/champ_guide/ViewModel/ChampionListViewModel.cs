using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections.ObjectModel;
using champ_guide.DataAccess;
using champ_guide.CommonUtil;
using System.Windows.Input;
using System.Windows;

namespace champ_guide.ViewModel
{
    class ChampionListViewModel : ViewModelBase
    {
        readonly champion_repo _champ_repro;
        BasicCommand _refresh_champ_list_command;

        public ObservableCollection<Model.c_champion> AllChampions
        {
            get;
            private set;
        }

        public ChampionListViewModel(champion_repo repro)
        {
            if (repro == null)
            {
                throw new ArgumentNullException("repro");
            }

            _champ_repro = repro;
            AllChampions = new ObservableCollection<Model.c_champion>(_champ_repro.GetChampions());
        }

        protected override void OnDispose()
        {
            AllChampions.Clear();
        }

        public ICommand RefreshChampListCommand
        {
            get
            {
                if (_refresh_champ_list_command == null)
                {
                    _refresh_champ_list_command = new BasicCommand(
                        param => this.RefreshChampListExecute(),
                        param => this.RefreshChampListCanExecute);
                }
                return _refresh_champ_list_command;
            }
        }

        void RefreshChampListExecute()
        {
            AllChampions.Clear();
            AllChampions = new ObservableCollection<Model.c_champion>(_champ_repro.GetChampions());
            OnPropertyChanged("AllChampions");
        }

        bool RefreshChampListCanExecute
        {
            get
            {
                return true;
            }
        }
    }
}
