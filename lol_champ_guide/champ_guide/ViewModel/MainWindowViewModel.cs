using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using champ_guide.DataAccess;
using System.Collections.ObjectModel;


namespace champ_guide.ViewModel
{
    public class MainWindowViewModel : ViewModelBase
    {
        readonly champion_repo _champ_repro;

        ObservableCollection<ViewModelBase> _view_models;

        public MainWindowViewModel()
        {
            _champ_repro = new champion_repo();
            ChampionListViewModel view_model = new ChampionListViewModel(_champ_repro);
            ViewModels.Add(view_model);
        }

        public ObservableCollection<ViewModelBase> ViewModels
        {
            get 
            {
                if (_view_models == null)
                {
                    _view_models = new ObservableCollection<ViewModelBase>();
                }
                return _view_models;
            }
        }
    }
}
