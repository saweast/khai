using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestingLab6
{
    internal class WorkWithDB
    {

        public void InsertCoefficients(List<Coefficient> coefs)
        {
            using (SqlConnection connection = new SqlConnection())
            {
                try
                {
                    connection.ConnectionString = "Server=localhost;Database=TestingData;"
                        + "User Id = UserTestingData;Password=1111;";
                    connection.Open();
                }
                catch(SqlException exc)
                {
                    Console.WriteLine(exc.Message);
                }

                SqlCommand command = new SqlCommand();
                command.Connection = connection;
                command.CommandText =
                    "INSERT INTO Coefficients (SequenceData, K1, K2, K3)" +
                    "VALUES (@sequenceData, @k1, @k2, @k3)";

                SqlParameter sequenceData = new SqlParameter("@sequenceData", SqlDbType.Float);
                SqlParameter paramK1 = new SqlParameter("@k1", SqlDbType.Float);
                SqlParameter paramK2 = new SqlParameter("@k2", SqlDbType.Float);
                SqlParameter paramK3 = new SqlParameter("@k3", SqlDbType.Float);

                command.Parameters.Add(sequenceData);
                command.Parameters.Add(paramK1);
                command.Parameters.Add(paramK2);
                command.Parameters.Add(paramK3);

                command.Prepare();

                foreach (Coefficient coef in coefs)
                {
                    command.Parameters["@sequenceData"].Value = coef.Sequence;
                    command.Parameters["@k1"].Value = coef.K1;
                    command.Parameters["@k2"].Value = coef.K2;
                    command.Parameters["@k3"].Value = coef.K3;
                    command.ExecuteNonQuery();
                }
            }
        }

        public List<Coefficient> GetUniqueCoefficients()
        {
            List<Coefficient> coefs = new List<Coefficient>();

            using (SqlConnection connection = new SqlConnection())
            {
                try
                {
                    connection.ConnectionString = "Server=localhost;Database=TestingData;"
                        + "User Id = UserTestingData;Password=1111;";
                    connection.Open();
                }
                catch (SqlException exc)
                {
                    Console.WriteLine(exc.Message);
                }

                SqlCommand command = new SqlCommand();
                command.Connection = connection;
                command.CommandText =
                    "SELECT DISTINCT SequenceData, K1, K2, K3 FROM Coefficients ORDER BY SequenceData;";

                SqlDataReader reader = command.ExecuteReader();
                try
                {
                    while (reader.Read())
                    {
                        Coefficient coef = new Coefficient();
                        coef.K1 = Convert.ToDouble(reader["K1"]);
                        coef.K2 = Convert.ToDouble(reader["K2"]);
                        coef.K3 = Convert.ToDouble(reader["K3"]);

                        coefs.Add(coef);
                    }
                }
                catch (SqlException exc)
                {
                    Console.WriteLine(exc.Message);
                }
                finally
                {
                    reader.Close();
                }
            }

            return coefs;
        }

        public void DeleteCoefficientsFromDB()
        {
            using (SqlConnection connection = new SqlConnection())
            {
                try
                {
                    connection.ConnectionString = "Server=localhost;Database=TestingData;"
                        + "User Id = UserTestingData;Password=1111;";
                    connection.Open();
                }
                catch (SqlException exc)
                {
                    Console.WriteLine(exc.Message);
                }

                SqlCommand command = new SqlCommand();
                command.Connection = connection;
                command.CommandText =
                    "DELETE FROM Coefficients;";
                command.ExecuteNonQuery();
            }
        }
    }
}
