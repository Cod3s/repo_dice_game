using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace shared_utility.ViewModel
{
    public abstract class ViewModelBase : INotifyPropertyChanged , IDisposable
    {
        protected ViewModelBase()
        {

        }

        public event PropertyChangedEventHandler PropertyChanged;

        protected virtual void OnPropertyChanged(string property_name)
        {
            PropertyChangedEventHandler handler = PropertyChanged;

            if (handler != null)
            {
                var args = new PropertyChangedEventArgs(property_name);
                handler(this, args);
            }
        }

        public void Dispose()
        {
            OnDispose();
        }

        protected virtual void OnDispose()
        {

        }
    }
}
