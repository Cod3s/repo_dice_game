using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;
using System.Diagnostics;

namespace champ_guide.CommonUtil
{
    public class BasicCommand : ICommand
    {
        readonly Action<object> _execute;
        readonly Predicate<object> _can_execute;

        public BasicCommand(Action<object> execute)
            : this(execute, null)
        {

        }

        public BasicCommand(Action<object> execute, Predicate<object> can_execute)
        {
            if (execute == null)
            {
                throw new ArgumentNullException("execute");
            }

            _execute = execute;
            _can_execute = can_execute;
        }

        [DebuggerStepThrough]
        public bool CanExecute(object parameter)
        {
            return _can_execute == null ? true : _can_execute(parameter);
        }

        public event EventHandler CanExecuteChanged
        {
            add { CommandManager.RequerySuggested += value; }
            remove { CommandManager.RequerySuggested -= value; }
        }

        public void Execute(object parameter)
        {
            _execute(parameter);
        }
    }
}
