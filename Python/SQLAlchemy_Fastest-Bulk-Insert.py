import io
from datetime import date

from sqlalchemy.engine.url import URL
from sqlalchemy import create_engine
from sqlalchemy import MetaData
from sqlalchemy import Table
from sqlalchemy import Column
from sqlalchemy import Integer
from sqlalchemy import String
from sqlalchemy import Date


db_url = {'drivername': 'postgres',
        'username': 'postgres',
        'password': 'postgres',
        'host': '192.168.99.100',
        'port': 5432}
engine = create_engine(URL(**db_url))

# create table
meta = MetaData(engine)
table = Table('userinfo', meta,
    Column('id', Integer, primary_key=True),
    Column('first_name', String),
    Column('age', Integer),
    Column('birth_day', Date),
)
meta.create_all()

# file-like object (tsv format)
datafile = io.StringIO()

# generate rows
for i in range(100):
    line = '\t'.join(
        [
            f'Name {i}',    # first_name
            str(18 + i),    # age
            str(date.today()),   # birth_day
        ]
    )
    datafile.write(line + '\n')

# reset file to start
datafile.seek(0)

# bulk insert via `COPY` statement
conn = engine.raw_connection()
with conn.cursor() as cur:
    # https://www.psycopg.org/docs/cursor.html#cursor.copy_from
    cur.copy_from(
        datafile,
        table.name,  # table name
        sep='\t',
        columns=('first_name', 'age', 'birth_day'),
    )
conn.commit()

