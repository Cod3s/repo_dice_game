using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;

namespace champ_guide.DataAccess
{
    public static class riot_api_interface
    {
        private static bool is_initialized = false;
        public enum e_locals { USA, EU_WEST, EU_EAST, KOREA }

        private const string api_key = "api_key=4d871a3f-0403-402c-98a4-85dde2eaf859";
        private const string api_host = "global.api.pvp.net";
        private static Dictionary<e_locals, string> _locals;
        static e_locals current_local = e_locals.USA;

        public static void initialize()
        {
            get_locals();
            is_initialized = true;
        }

        private static void get_locals()
        {
            _locals = new Dictionary<e_locals, string>();
            _locals.Add(e_locals.USA, "na");
            _locals.Add(e_locals.EU_EAST, "eune");
            _locals.Add(e_locals.EU_WEST, "euw");
            _locals.Add(e_locals.KOREA, "kr");
        }

        private static void add_default_headers(ref HttpWebRequest in_request)
        {
            in_request.UserAgent = "Riot-Games-Developer-Portal";
            in_request.Headers.Add("Accept-Language", "en-US");
            in_request.Headers.Add("Accept-Charset", "ISO-8859-1,utf-8");
            in_request.Headers.Add("Origin", "https://developer.riotgames.com");
        }

        public static void get_all_champions()
        {
            if (is_initialized == false)
            {
                return; 
            }

            StringBuilder str_build = new StringBuilder();

            str_build.AppendFormat(@"https://{0}/api/lol/static-data/{1}/v1.2/champion?champData=all&{2}", api_host, _locals[current_local], api_key);

            Uri httpSite = new Uri(str_build.ToString());

            HttpWebRequest wreq = (HttpWebRequest)WebRequest.Create(httpSite);

            add_default_headers(ref wreq);

            var main_response = wreq.GetResponse();

            var main_stream = main_response.GetResponseStream();

            object temp_state = false;
            IAsyncResult result = (IAsyncResult)wreq.BeginGetResponse(
                new AsyncCallback(param =>
                    {
                        WebResponse response = wreq.EndGetResponse(param);

                        Stream response_stream = response.GetResponseStream();

                        int x = 10;

                    }), temp_state);
        }
    }
}
