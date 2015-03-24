using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;
using champ_guide.ViewModel;

namespace champ_guide
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
        protected override void OnStartup(StartupEventArgs e)
        {
            base.OnStartup(e);
            MainWindow window = new MainWindow();
            MainWindowViewModel view_model = new MainWindowViewModel();
            window.DataContext = view_model;
            window.Show();
        }
    }
}
