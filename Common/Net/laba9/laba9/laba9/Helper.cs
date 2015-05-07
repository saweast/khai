﻿using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;


namespace laba9
{
    class Helper
    {
        public static void SaveImageCapture(System.Drawing.Image image, int clientsNumb)
        {
            SaveFileDialog s = new SaveFileDialog();
            //s.FileName = "Image"+clientsNumb;// Default file name
            //s.DefaultExt = ".Jpg";// Default file extension
            //s.Filter = "Image (.jpg)|*.jpg"; // Filter files by extension

            // Show save file dialog box
            // Process save file dialog box results
            //if (s.ShowDialog()==DialogResult.OK){
                // Save Image
                string filename = clientsNumb + ".jpg";
                FileStream fstream = new FileStream(filename, FileMode.Create);
                image.Save(fstream, System.Drawing.Imaging.ImageFormat.Jpeg);
                fstream.Close();

            //}

        }
    }
}
