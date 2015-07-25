using System.Collections.Generic;
using System.Linq;
using System.Xml;

namespace champ_guide.CommonUtil
{
    public class XmlDataNode
    {
        public string ElementName;
        public Dictionary<string, object> AttributeData;
        public List<XmlDataNode> ValueNodes;
        public object ValueData;
        public int DepthValue;

        public XmlDataNode()
        {
            ElementName = string.Empty;
            AttributeData = new Dictionary<string, object>();
            ValueNodes = new List<XmlDataNode>();
            DepthValue = 0;
        }
    }

    public static class XmlParser
    {
        public static List<XmlDataNode> read_xml_file_for_data(string file_name)
        {
            List<XmlDataNode> data = new List<XmlDataNode>();


            XmlReaderSettings read_settings = new XmlReaderSettings();
            read_settings.CloseInput = true;
            read_settings.IgnoreComments = true;
            read_settings.IgnoreWhitespace = true;
            // TODO:
            // do basic file validation first
            using (XmlReader reader = XmlReader.Create(file_name, read_settings))
            {
                while(reader.Read())
                {
                    if (reader.NodeType == XmlNodeType.Element)
                    {
                        XmlDataNode node = new XmlDataNode();
                        node.ElementName = reader.Name;
                        node.DepthValue = reader.Depth;

                        bool should_add_to_parent = false;

                        if (data.Any())
                        {
                            should_add_to_parent = data.Where(a => a.DepthValue == node.DepthValue - 1).Any() ? true : false;
                        }
                       
                        if (reader.HasAttributes == true)
                        {
                            node.AttributeData = read_all_attribibutes(reader);
                        }

                        if (should_add_to_parent)
                        {
                            // We'll see if I need to do a deep copy here
                            //XmlDataNode parent_version = new XmlDataNode();
                            //parent_version.AttributeData = node.AttributeData;
                            data
                                .Where(a => a.DepthValue == node.DepthValue - 1)
                                .Last()
                                    .ValueNodes.Add(node);
                        }

                        data.Add(node);
                    }

                    if (reader.NodeType == XmlNodeType.Text)
                    {
                        data.Last().ValueData = reader.Value;
                    }
                }
            }

            return data;
        }

        private static Dictionary<string, object> read_all_attribibutes(XmlReader reader)
        {
            Dictionary<string, object> attributes = new Dictionary<string, object>();

            reader.MoveToFirstAttribute();
            attributes.Add(reader.Name, reader.Value);

            while (reader.MoveToNextAttribute())
            {
                attributes.Add(reader.Name, reader.Value);
            }

            return attributes;
        }

    }
}
