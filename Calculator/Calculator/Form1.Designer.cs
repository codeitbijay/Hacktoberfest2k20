namespace Calculator
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.lblnumber1 = new System.Windows.Forms.Label();
            this.lblnumber2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.txtnumber1 = new System.Windows.Forms.TextBox();
            this.txtnumber2 = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.lblequal = new System.Windows.Forms.Label();
            this.plusmark = new System.Windows.Forms.Button();
            this.minusmark = new System.Windows.Forms.Button();
            this.multimark = new System.Windows.Forms.Button();
            this.dividemark = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lblnumber1
            // 
            this.lblnumber1.AutoSize = true;
            this.lblnumber1.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblnumber1.ForeColor = System.Drawing.SystemColors.Control;
            this.lblnumber1.Location = new System.Drawing.Point(12, 113);
            this.lblnumber1.Name = "lblnumber1";
            this.lblnumber1.Size = new System.Drawing.Size(141, 29);
            this.lblnumber1.TabIndex = 0;
            this.lblnumber1.Text = "Number 1 :";
            // 
            // lblnumber2
            // 
            this.lblnumber2.AutoSize = true;
            this.lblnumber2.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblnumber2.ForeColor = System.Drawing.SystemColors.Control;
            this.lblnumber2.Location = new System.Drawing.Point(12, 162);
            this.lblnumber2.Name = "lblnumber2";
            this.lblnumber2.Size = new System.Drawing.Size(141, 29);
            this.lblnumber2.TabIndex = 1;
            this.lblnumber2.Text = "Number 2 :";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.Color.Red;
            this.label3.Location = new System.Drawing.Point(136, 36);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(83, 37);
            this.label3.TabIndex = 2;
            this.label3.Text = "(ಠ_ಠ)";
            // 
            // txtnumber1
            // 
            this.txtnumber1.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtnumber1.Location = new System.Drawing.Point(177, 111);
            this.txtnumber1.Name = "txtnumber1";
            this.txtnumber1.Size = new System.Drawing.Size(142, 31);
            this.txtnumber1.TabIndex = 3;
            // 
            // txtnumber2
            // 
            this.txtnumber2.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtnumber2.Location = new System.Drawing.Point(177, 160);
            this.txtnumber2.Name = "txtnumber2";
            this.txtnumber2.Size = new System.Drawing.Size(142, 31);
            this.txtnumber2.TabIndex = 4;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Lucida Sans Typewriter", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.SystemColors.Control;
            this.label4.Location = new System.Drawing.Point(-3, 9);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(362, 27);
            this.label4.TabIndex = 5;
            this.label4.Text = "Don\'t touch my Calculator";
            // 
            // lblequal
            // 
            this.lblequal.AutoSize = true;
            this.lblequal.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblequal.Location = new System.Drawing.Point(172, 359);
            this.lblequal.Name = "lblequal";
            this.lblequal.Size = new System.Drawing.Size(0, 29);
            this.lblequal.TabIndex = 6;
            // 
            // plusmark
            // 
            this.plusmark.BackColor = System.Drawing.Color.SlateGray;
            this.plusmark.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.plusmark.ForeColor = System.Drawing.SystemColors.Control;
            this.plusmark.Location = new System.Drawing.Point(37, 253);
            this.plusmark.Name = "plusmark";
            this.plusmark.Size = new System.Drawing.Size(37, 36);
            this.plusmark.TabIndex = 7;
            this.plusmark.Text = "+";
            this.plusmark.UseVisualStyleBackColor = false;
            this.plusmark.Click += new System.EventHandler(this.button1_Click);
            // 
            // minusmark
            // 
            this.minusmark.BackColor = System.Drawing.Color.SlateGray;
            this.minusmark.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.minusmark.ForeColor = System.Drawing.SystemColors.Control;
            this.minusmark.Location = new System.Drawing.Point(101, 253);
            this.minusmark.Name = "minusmark";
            this.minusmark.Size = new System.Drawing.Size(37, 36);
            this.minusmark.TabIndex = 8;
            this.minusmark.Text = "-";
            this.minusmark.UseVisualStyleBackColor = false;
            this.minusmark.Click += new System.EventHandler(this.button2_Click);
            // 
            // multimark
            // 
            this.multimark.BackColor = System.Drawing.Color.SlateGray;
            this.multimark.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.multimark.ForeColor = System.Drawing.SystemColors.Control;
            this.multimark.Location = new System.Drawing.Point(160, 253);
            this.multimark.Name = "multimark";
            this.multimark.Size = new System.Drawing.Size(37, 36);
            this.multimark.TabIndex = 9;
            this.multimark.Text = "×";
            this.multimark.UseVisualStyleBackColor = false;
            this.multimark.Click += new System.EventHandler(this.multimark_Click);
            // 
            // dividemark
            // 
            this.dividemark.BackColor = System.Drawing.Color.SlateGray;
            this.dividemark.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.dividemark.ForeColor = System.Drawing.SystemColors.Control;
            this.dividemark.Location = new System.Drawing.Point(222, 253);
            this.dividemark.Name = "dividemark";
            this.dividemark.Size = new System.Drawing.Size(37, 36);
            this.dividemark.TabIndex = 10;
            this.dividemark.Text = "÷";
            this.dividemark.UseVisualStyleBackColor = false;
            this.dividemark.Click += new System.EventHandler(this.dividemark_Click);
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.SlateGray;
            this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.ForeColor = System.Drawing.SystemColors.Control;
            this.button1.Location = new System.Drawing.Point(282, 253);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(37, 36);
            this.button1.TabIndex = 11;
            this.button1.Text = "C";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click_1);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(54)))), ((int)(((byte)(58)))), ((int)(((byte)(71)))));
            this.ClientSize = new System.Drawing.Size(357, 450);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.dividemark);
            this.Controls.Add(this.multimark);
            this.Controls.Add(this.minusmark);
            this.Controls.Add(this.plusmark);
            this.Controls.Add(this.lblequal);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.txtnumber2);
            this.Controls.Add(this.txtnumber1);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.lblnumber2);
            this.Controls.Add(this.lblnumber1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblnumber1;
        private System.Windows.Forms.Label lblnumber2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txtnumber1;
        private System.Windows.Forms.TextBox txtnumber2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label lblequal;
        private System.Windows.Forms.Button plusmark;
        private System.Windows.Forms.Button minusmark;
        private System.Windows.Forms.Button multimark;
        private System.Windows.Forms.Button dividemark;
        private System.Windows.Forms.Button button1;
    }
}

