using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Xml;
using System.IO;

namespace champ_guide.ViewModel
{
    public class ChampionDetailViewModel : ViewModelBase
    {
        private ObservableCollection<UserControl> _custom_control_menu_items;
        private List<CommonUtil.XmlDataNode> custom_details_xml_data;

        public ObservableCollection<UserControl> CustomControlMenuItems
        {
            get
            {
                if (_custom_control_menu_items == null)
                {
                    _custom_control_menu_items = new ObservableCollection<UserControl>();
                    custom_details_xml_data = CommonUtil.XmlParser.read_xml_file_for_data(@"data\test_xml_file.xml");

                    var options_only = custom_details_xml_data.Where(a => a.ElementName == "Option");

                    foreach (var item in options_only)
                    {
                        var obj = new View.TestUserControl();

                        if (item.AttributeData.Keys.Contains("label"))
                        {
                            obj.OptionLabel.Text = item.AttributeData["label"].ToString();
                        }
                        else
                        {
                            obj.OptionLabel.Text = "No Label";
                        }

                        if (item.ValueNodes.Any())
                        {
                            foreach (var data_item in item.ValueNodes[0].ValueNodes)
                            {
                                obj.OptionValues.Items.Add(data_item.ValueData);
                            }
                        }

                        obj.OptionValues.IsEnabled = obj.OptionValues.Items.Count > 0;

                        _custom_control_menu_items.Add(obj);
                    }
                }

                var test_obj = new View.TestUserControl();
                //test_obj.OptionLabel.Text = "activity_option_real";

                //test_obj.OptionValues.Items.Add(0.0);
                //test_obj.OptionValues.Items.Add(0.5);
                //test_obj.OptionValues.Items.Add(1.0);
                //test_obj.OptionValues.Items.Add(2.0);

                //var test_bool_obj = new View.TestUserControl();
                //test_bool_obj.OptionLabel.Text = "activity_option_bool";
                //test_bool_obj.OptionValues.Items.Add(true);
                //test_bool_obj.OptionValues.Items.Add(false);

                //_custom_control_menu_items.Add(test_obj);
                //_custom_control_menu_items.Add(test_bool_obj);
           
                return _custom_control_menu_items;
            }
        }


        public ChampionDetailViewModel()
        {

        }
    }
}
