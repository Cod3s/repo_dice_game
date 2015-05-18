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
        Model.c_champion _selected_champion;

        public ObservableCollection<Model.c_champion> AllChampions
        {
            get;
            private set;
        }

        public Model.c_champion SelectedChampion
        {
            get
            {               
                return _selected_champion;
            }
            set
            {
                _selected_champion = value;
                OnPropertyChanged("SelectedChampion");
                OnPropertyChanged("ChampionDetails");
                OnPropertyChanged("ChampionDetailsWidth");
            }
        }

        public List<Model.c_champion_detail> ChampionDetails
        {
            get
            {
                if (_selected_champion == null)
                {
                    return null;
                }

                return _selected_champion.ChampionDetails;
            }
        }

        // TODO: Make this property better... or work if possible
        public double ChampionDetailsWidth
        {
            get
            {
                return 1000;

                //if (_selected_champion == null)
                //{
                //    return 0;
                //}

                //int current_max_length = 0;
                //foreach (var label in _selected_champion.ChampionDetails)
                //{
                //    if (label.Label.Length> current_max_length)
                //    {
                //        current_max_length = label.Label.Length;
                //    }
                //}

                //return current_max_length * 10000;
            }
        }

        public ChampionListViewModel(champion_repo repro)
        {
            if (repro == null)
            {
                throw new ArgumentNullException("repro");
            }

            _champ_repro = repro;
            AllChampions = new ObservableCollection<Model.c_champion>(_champ_repro.GetChampions());

            _selected_champion = null;
        }

        protected override void OnDispose()
        {
            AllChampions.Clear();
        }

        #region RefreshChampListCommandRegion
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
        #endregion

    }
}
